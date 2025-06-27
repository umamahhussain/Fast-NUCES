package com.example.scheduler;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.cardview.widget.CardView;
import androidx.fragment.app.Fragment;

import com.google.android.material.datepicker.MaterialDatePicker;
import com.google.android.material.timepicker.MaterialTimePicker;
import com.google.android.material.timepicker.TimeFormat;

import java.util.Calendar;
import java.util.List;
import java.util.Locale;

public class ScheduleFragment extends Fragment {

    private EditText editTitle, editDescription, editDateTime;
    private Button btnAdd;
    private LinearLayout taskList;
    private TaskDatabaseHelper dbHelper;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater,
                             @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_schedule, container, false);

        editTitle = view.findViewById(R.id.editTitle);
        editDescription = view.findViewById(R.id.editDescription);
        editDateTime = view.findViewById(R.id.editDateTime);
        btnAdd = view.findViewById(R.id.btnAddTask);
        taskList = view.findViewById(R.id.taskList);

        dbHelper = new TaskDatabaseHelper(getContext());

        // Optional: Show date picker on click
        editDateTime.setOnClickListener(v -> showDateTimePicker());

        btnAdd.setOnClickListener(v -> {
            String title = editTitle.getText().toString().trim();
            String desc = editDescription.getText().toString().trim();
            String datetime = editDateTime.getText().toString().trim();

            if (title.isEmpty()) {
                Toast.makeText(getContext(), "Please enter a title", Toast.LENGTH_SHORT).show();
                return;
            }

            if (datetime.isEmpty()) {
                Toast.makeText(getContext(), "Please select date and time", Toast.LENGTH_SHORT).show();
                return;
            }

            Toast.makeText(getContext(), "Saving task...", Toast.LENGTH_SHORT).show();
            dbHelper.insertTask(title, desc, datetime);
            Toast.makeText(getContext(), "Task saved!", Toast.LENGTH_SHORT).show();

            editTitle.setText("");
            editDescription.setText("");
            editDateTime.setText("");

            loadTasks(); // Refresh task list
        });


        loadTasks();
        return view;
    }

    private void loadTasks() {
        List<TaskModel> tasks = dbHelper.getFutureTasks();
        taskList.removeAllViews();

        Toast.makeText(getContext(), "Tasks fetched: " + tasks.size(), Toast.LENGTH_SHORT).show();

        if (tasks.isEmpty()) {
            TextView emptyView = new TextView(getContext());
            emptyView.setText("No upcoming tasks");
            emptyView.setTextSize(16);
            emptyView.setPadding(20, 20, 20, 20);
            taskList.addView(emptyView);
            return;
        }

        for (TaskModel task : tasks) {
            View taskView = getLayoutInflater().inflate(R.layout.item_task_card, taskList, false);

            TextView title = taskView.findViewById(R.id.txtCardTitle);
            TextView desc = taskView.findViewById(R.id.txtCardDesc);
            TextView time = taskView.findViewById(R.id.txtCardTime);

            title.setText(task.title);
            desc.setText(task.description);
            time.setText(task.datetime);

            taskList.addView(taskView);
        }
    }

    private void showDateTimePicker() {
        MaterialDatePicker<Long> datePicker = MaterialDatePicker.Builder.datePicker()
                .setTitleText("Select Date")
                .build();

        datePicker.addOnPositiveButtonClickListener(selection -> {
            // Create a calendar with the selected date
            Calendar calendar = Calendar.getInstance();
            calendar.setTimeInMillis(selection);

            // Store selected date
            int year = calendar.get(Calendar.YEAR);
            int month = calendar.get(Calendar.MONTH); // 0-based
            int day = calendar.get(Calendar.DAY_OF_MONTH);

            // Show time picker
            MaterialTimePicker timePicker = new MaterialTimePicker.Builder()
                    .setTitleText("Select Time")
                    .setTimeFormat(TimeFormat.CLOCK_24H)
                    .setHour(12)  // Default hour
                    .setMinute(0) // Default minute
                    .build();

            timePicker.addOnPositiveButtonClickListener(v -> {
                int hour = timePicker.getHour();
                int minute = timePicker.getMinute();

                // Combine both date and time correctly
                Calendar finalCal = Calendar.getInstance();
                finalCal.set(year, month, day, hour, minute);

                String formattedDateTime = String.format(Locale.getDefault(),
                        "%04d-%02d-%02d %02d:%02d:%02d", year, month + 1, day, hour, minute, 0);


                editDateTime.setText(formattedDateTime);
            });

            timePicker.show(getParentFragmentManager(), "MATERIAL_TIME_PICKER");
        });

        datePicker.show(getParentFragmentManager(), "MATERIAL_DATE_PICKER");
    }

}

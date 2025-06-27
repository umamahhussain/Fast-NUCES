package com.example.scheduler;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import java.util.List;

public class PastFragment extends Fragment {

    private TaskDatabaseHelper dbHelper;
    private LinearLayout pastTaskList;

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_past, container, false);

        dbHelper = new TaskDatabaseHelper(requireContext());
        pastTaskList = view.findViewById(R.id.pastTaskList);

        loadPastTasks();

        return view;
    }

    private void loadPastTasks() {
        pastTaskList.removeAllViews();
        List<TaskModel> tasks = dbHelper.getPastTasks();

        for (TaskModel task : tasks) {
            View taskView = getLayoutInflater().inflate(R.layout.item_task_card, pastTaskList, false);

            TextView title = taskView.findViewById(R.id.txtCardTitle);
            TextView desc = taskView.findViewById(R.id.txtCardDesc);
            TextView time = taskView.findViewById(R.id.txtCardTime);

            title.setText(task.title);
            desc.setText(task.description);
            time.setText(task.datetime);

            pastTaskList.addView(taskView);
        }
    }
}

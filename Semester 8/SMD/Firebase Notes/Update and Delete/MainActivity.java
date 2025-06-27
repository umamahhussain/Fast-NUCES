package com.example.firebasepractice;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.recyclerview.widget.RecyclerView;

import com.firebase.ui.database.FirebaseRecyclerOptions;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.textfield.TextInputEditText;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Objects;

public class MainActivity extends AppCompatActivity {

    private FloatingActionButton addBtn;
    private RecyclerView notesRV;
    NotesAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        init();


        addBtn.setOnClickListener(v -> {

            View view = LayoutInflater.from(this).inflate(R.layout.add_new_note_dialog, null);

            TextView timestamp = view.findViewById(R.id.timestamp);
            TextInputEditText etTitle = view.findViewById(R.id.etTitle);
            TextInputEditText etContent = view.findViewById(R.id.etContent);

            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
            Date date = new Date();
            timestamp.setText(formatter.format(date));

            AlertDialog.Builder addNote =
                    new AlertDialog.Builder(this)
                            .setTitle("Add Note")
                            .setView(view)
                            .setPositiveButton("Save", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    String title = Objects.requireNonNull(etTitle.getText()).toString().trim();
                                    String content = Objects.requireNonNull(etContent.getText()).toString().trim();

                                    HashMap <String, Object> data = new HashMap<>();
                                    data.put("title", title);
                                    data.put("content", content);
                                    data.put("timestamp", timestamp.getText().toString());

                                    FirebaseDatabase.getInstance()
                                            .getReference()
                                            .child("Notes")
                                            .push()
                                            .setValue(data)
                                            .addOnSuccessListener(new OnSuccessListener<Void>() {
                                                @Override
                                                public void onSuccess(Void unused) {
                                                    Toast.makeText(MainActivity.this, "Note Created", Toast.LENGTH_SHORT).show();
                                                }
                                            })
                                            .addOnFailureListener(new OnFailureListener() {
                                                @Override
                                                public void onFailure(@NonNull Exception e) {
                                                    Toast.makeText(MainActivity.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                                                }
                                            });
                                }
                            })
                            .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    dialog.dismiss();
                                }
                            });

            addNote.create();
            addNote.show();
        });
    }

    private void init(){
        addBtn = findViewById(R.id.addBtn);
        notesRV = findViewById(R.id.rvNotes);

        Query query = FirebaseDatabase.getInstance()
                .getReference()
                .child("Notes");

        FirebaseRecyclerOptions<Note> options =
                new FirebaseRecyclerOptions.Builder<Note>()
                        .setQuery(query, Note.class)
                        .build();

        adapter = new NotesAdapter( options, this );
        notesRV.setAdapter(adapter);
    }

    @Override
    protected void onStart() {
        super.onStart();
        adapter.startListening();
    }

    @Override
    protected void onStop() {
        super.onStop();
        adapter.stopListening();
    }
}
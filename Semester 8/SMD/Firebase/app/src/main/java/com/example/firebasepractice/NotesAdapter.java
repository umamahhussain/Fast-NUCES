package com.example.firebasepractice;

import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.recyclerview.widget.RecyclerView;

import com.firebase.ui.database.FirebaseRecyclerAdapter;
import com.firebase.ui.database.FirebaseRecyclerOptions;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.material.textfield.TextInputEditText;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;

public class NotesAdapter extends FirebaseRecyclerAdapter <Note, NotesAdapter.NotesViewHolder> {

    Context parent;
    public NotesAdapter(@NonNull FirebaseRecyclerOptions<Note> options, Context context) {
        super(options);
        parent= context;
    }



    @Override
    protected void onBindViewHolder(@NonNull NotesViewHolder holder, int position, @NonNull Note model) {

        holder.tvTitle.setText(model.getTitle());
        holder.tvContent.setText(model.getContent());
        holder.tvTimestamp.setText(model.getTimestamp());

        holder.del.setOnClickListener(v->{
            AlertDialog.Builder confirm = new AlertDialog.Builder(parent)
                    .setTitle("Confirm")
                    .setMessage("Do you really want to delete this record?")
                    .setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            getRef(position)
                                    .removeValue()
                                    .addOnSuccessListener(new OnSuccessListener<Void>() {
                                        @Override
                                        public void onSuccess(Void unused) {
                                            Toast.makeText(parent, "Record Deleted", Toast.LENGTH_SHORT).show();
                                        }
                                    });
                        }
                    })
                    .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {

                        }
                    });
                    confirm.create();
                    confirm.show();
        });

        holder.edit.setOnClickListener(v-> {
            View view = LayoutInflater.from(parent).inflate(R.layout.add_new_note_dialog, null);

            TextInputEditText etTitle = view.findViewById(R.id.etTitle);
            TextInputEditText etContent = view.findViewById(R.id.etContent);
            TextView timestamp = view.findViewById(R.id.timestamp);

            etTitle.setText(model.getTitle());
            etContent.setText(model.getContent());

            SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
            Date date = new Date();
            timestamp.setText(formatter.format(date));


            AlertDialog.Builder updateDialog = new AlertDialog.Builder(parent)
                    .setTitle("Update Dialog")
                    .setView(view)
                    .setPositiveButton("Update", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {

                            String title = etTitle.getText().toString().trim();
                            String content = etContent.getText().toString().trim();
                            String stamp = timestamp.getText().toString();

                            HashMap<String, Object> data = new HashMap<>();
                            data.put("title", title);
                            data.put("content", content);
                            data.put("timestamp", stamp);

                            getRef(position)
                                    .updateChildren(data)
                                    .addOnSuccessListener(new OnSuccessListener<Void>() {
                                        @Override
                                        public void onSuccess(Void unused) {
                                            Toast.makeText(parent, "Note Updated", Toast.LENGTH_SHORT).show();
                                        }
                                    })
                                    .addOnFailureListener(new OnFailureListener() {
                                        @Override
                                        public void onFailure(@NonNull Exception e) {

                                        }
                                    });
                        }
                    })
                    .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {

                        }
                    });
            updateDialog.create();
            updateDialog.show();

        });

    }





    @NonNull @Override
    public NotesViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
       View v = LayoutInflater.from(parent.getContext())
               .inflate(R.layout.single_note_item_design, parent, false);
       return new NotesViewHolder(v);
    }




    public class NotesViewHolder extends RecyclerView.ViewHolder {
        TextView tvTitle, tvContent, tvTimestamp;
        ImageView edit, del;

        public NotesViewHolder(@NonNull View itemView) {
            super(itemView);
            tvTitle = itemView.findViewById(R.id.tvTitle);
            tvContent = itemView.findViewById(R.id.tvContent);
            tvTimestamp = itemView.findViewById(R.id.tvTimestamp);
            edit = itemView.findViewById(R.id.editBtn);
            del = itemView.findViewById(R.id.delBtn);
        }
    }


}

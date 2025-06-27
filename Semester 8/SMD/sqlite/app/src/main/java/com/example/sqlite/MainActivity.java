package com.example.sqlite;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.google.android.material.textfield.TextInputEditText;

public class MainActivity extends AppCompatActivity {

    TextInputEditText etTitle, etPrice, etDesc, etDate;
    Button addBtn, viewBtn, delBtn, updateBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        init();
        KhaataDB db = new KhaataDB(this);

        addBtn.setOnClickListener(v->{
            String title = etTitle.getText().toString().trim();
            String desc = etDesc.getText().toString().trim();
            String date = etDate.getText().toString().trim();
            String price = etPrice.getText().toString().trim();

            db.open();
            long records = db.addNewKhaata(title, desc, date, price);
            db.close();
            Toast.makeText(this, "Record Created. Total records: " + records, Toast.LENGTH_SHORT).show();
        });

        delBtn.setOnClickListener(v->{
            db.open();
            db.removeKhaata("1");
            db.close();
        });

        updateBtn.setOnClickListener(v->{
            db.open();
            db.updateKhaata("2", "umamah", "lessgobaby", "020202", "69");
            db.close();
        });

        viewBtn.setOnClickListener(v->{
            Intent i = new Intent(this, ViewAll.class);
            startActivity(i);
        });

    }
    private void init(){
        etDate = findViewById(R.id.date);
        etTitle = findViewById(R.id.title);
        etPrice = findViewById(R.id.price);
        etDesc = findViewById(R.id.desc);
        addBtn = findViewById(R.id.addBtn);
        viewBtn = findViewById(R.id.viewBtn);
        delBtn = findViewById(R.id.delBtn);
        updateBtn = findViewById(R.id.updateBtn);
    }
}
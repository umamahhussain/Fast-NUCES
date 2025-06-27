package com.example.sqlite;

import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class ViewAll extends AppCompatActivity {

    TextView viewAll;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_view_all);

        viewAll = findViewById(R.id.viewAll);
        KhaataDB db = new KhaataDB(this);
        db.open();
        viewAll.setText(db.getAllKhaatas());
        db.close();

    }
}
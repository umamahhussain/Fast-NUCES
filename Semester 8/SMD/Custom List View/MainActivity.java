package com.example.customlv;

import android.os.Bundle;
import android.widget.ListView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    ListView personsLV;
    PersonAdapter adapter;
    ArrayList<Person> personsList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        init();
    }

    private void init()
    {
        personsLV = findViewById(R.id.lvPersons);
        personsList = new ArrayList<>();
        personsList.add( new Person( "umi", 23, R.drawable.one) );
        personsList.add( new Person( "ali", 22, R.drawable.one) );
        personsList.add( new Person( "harris", 25, R.drawable.one) );
        personsList.add( new Person( "ahmed", 35, R.drawable.one) );
        personsList.add( new Person( "faiqa", 95, R.drawable.one) );

        adapter = new PersonAdapter(this, R.layout.list_item, personsList);
        personsLV.setAdapter(adapter);
    }
}


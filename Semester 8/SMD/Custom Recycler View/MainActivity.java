package com.example.recyclerview;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;
import androidx.fragment.app.FragmentManager;

public class MainActivity extends AppCompatActivity implements PersonAdapter.ContactSelected {

    TextView name, age, num;
    EditText etName, etAge, etNum;
    Button addPersonBtn;
    ListFragment listFragmentObject;
    FragmentManager manager;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        init();



        addPersonBtn.setOnClickListener(v->{
            String tempName = etName.getText().toString().trim();
            String tempNum = etNum.getText().toString().trim();
            String tempAge = etAge.getText().toString().trim();

            if(tempName.isEmpty() || tempNum.isEmpty() || tempAge.isEmpty()){
                Toast.makeText(this, "Enter all fields carefully", Toast.LENGTH_SHORT).show();
            }
            else{
                ContactsData.contacts.add(new Person(tempName,tempNum,Integer.parseInt(tempAge)));
                listFragmentObject.onDatasetChange();
                etName.setText("");
                etNum.setText("");
                etAge.setText("");
            }
        });
    }

    private void init() {
        name = findViewById(R.id.name);
        age = findViewById(R.id.age);
        num = findViewById(R.id.num);
        onContactClick(0);

        etName = findViewById(R.id.setName);
        etAge = findViewById(R.id.setAge);
        etNum = findViewById(R.id.setNum);
        addPersonBtn = findViewById(R.id.addPerson);

        manager = getSupportFragmentManager();
        listFragmentObject = (ListFragment) manager.findFragmentById(R.id.listfrag);
    }

    @Override
    public void onContactClick(int index) {
        name.setText(ContactsData.contacts.get(index).getName());
        age.setText(String.valueOf(ContactsData.contacts.get(index).getAge())); // FIXED
        num.setText(ContactsData.contacts.get(index).getContact());
    }

}
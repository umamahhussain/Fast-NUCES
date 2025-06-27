package com.example.customlv;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.List;

public class PersonAdapter extends ArrayAdapter<Person>
{
    Context context;
    public PersonAdapter(@NonNull Context context, int resource, @NonNull List<Person> objects) {
        super(context, resource, objects);
        this.context = context;
    }

    @NonNull @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

        if(convertView == null){
            convertView = LayoutInflater.from(context).inflate(R.layout.list_item, parent, false );
        }

        Person P = getItem(position);
        ImageView pic = convertView.findViewById( R.id.pic );
        TextView name = convertView.findViewById( R.id.name );
        TextView age = convertView.findViewById( R.id.age );

        name.setText("Name: " + P.getName() );
        age.setText("Age: " + P.getAge() );
        pic.setImageResource(P.getPicture());

        convertView.setOnClickListener(v -> {
            Toast.makeText(context, P.getName() + " is " + P.getAge() + " years old.", Toast.LENGTH_SHORT).show();
        });


        return convertView;
    }

}

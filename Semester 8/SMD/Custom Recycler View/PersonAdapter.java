package com.example.recyclerview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class PersonAdapter extends RecyclerView.Adapter<PersonAdapter.ViewHolder> {

    ArrayList<Person> people;
    ContactSelected obj;
    public PersonAdapter(Context context, ArrayList<Person> list) {
        people = list;
        obj = (ContactSelected) context;
    }

    public interface ContactSelected{
        public void onContactClick(int index);
    }


    public class ViewHolder extends RecyclerView.ViewHolder {
        TextView tvName ;
        public ViewHolder(@NonNull View itemView)
        {
            super(itemView);
            tvName = itemView.findViewById(R.id.ListName);
            itemView.setOnClickListener( v ->{
                obj.onContactClick(people.indexOf((Person)itemView.getTag()));
            });
        }
    }


    @NonNull @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.list_layout, parent, false);
        return new ViewHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.tvName.setText(people.get(position).getName());
        holder.itemView.setTag(people.get(position));
    }

    @Override
    public int getItemCount() {
        return people.size();
    }
}

package com.example.recyclerview;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

public class ListFragment extends Fragment {

    RecyclerView RV;
    RecyclerView.LayoutManager layoutManager;
    RecyclerView.Adapter myAdapter;
    View v;

    public ListFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        v = inflater.inflate(R.layout.fragment_list, container, false);
        return  v;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        RV = v.findViewById(R.id.list);
        RV.setHasFixedSize(true);   //for efficiency
        layoutManager = new LinearLayoutManager(getContext());
        RV.setLayoutManager(layoutManager);

        myAdapter = new PersonAdapter(getContext(), ContactsData.contacts);
        RV.setAdapter(myAdapter);
    }


    public void onDatasetChange(){
        myAdapter.notifyDataSetChanged();
    }

}
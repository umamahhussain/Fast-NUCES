package com.example.recyclerview;

import android.app.Application;

import java.util.ArrayList;

public class ContactsData extends Application {

    public static ArrayList<Person> contacts;
    @Override
    public void onCreate() {
        super.onCreate();
        contacts = new ArrayList<>();
        contacts.add( new Person ("Umamah", "11111", 23) );
        contacts.add( new Person ("Faiqa", "22222", 24) );
        contacts.add( new Person ("Monkey", "33333", 27) );
        contacts.add( new Person ("Elephant", "44444", 93) );
        contacts.add( new Person ("Doggy", "55555", 230) );
        contacts.add( new Person ("Catto", "66666", 29) );
    }
}

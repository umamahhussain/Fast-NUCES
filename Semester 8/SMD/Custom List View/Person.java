package com.example.customlv;

public class Person {
    private String name;
    private int age;
    private int picture;


    public Person(String name, int age, int picture) {
        this.name = name;
        this.age = age;
        this.picture = picture;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getPicture() {
        return picture;
    }

    public void setPicture(int picture) {
        this.picture = picture;
    }
}

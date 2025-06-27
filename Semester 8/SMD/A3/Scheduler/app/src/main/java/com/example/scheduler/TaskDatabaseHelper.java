package com.example.scheduler;

import static java.security.AccessController.getContext;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;

public class TaskDatabaseHelper extends SQLiteOpenHelper {

    private static final String DB_NAME = "tasks.db";
    private static final int DB_VERSION = 1;

    public TaskDatabaseHelper(Context context) {
        super(context, DB_NAME, null, DB_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE tasks (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "title TEXT, " +
                "description TEXT, " +
                "datetime TEXT, " +
                "status TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS tasks");
        onCreate(db);
    }

    public void insertTask(String title, String description, String datetime) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("title", title);
        values.put("description", description);
        values.put("datetime", datetime);
        values.put("status", "pending");
        long result = db.insert("tasks", null, values);

        if (result == -1) {
            Log.e("DB_INSERT", "Failed to insert task");
        } else {
            Log.d("DB_INSERT", "Task inserted successfully with ID: " + result);
        }
    }

    public List<TaskModel> getPastTasks() {
        List<TaskModel> tasks = new ArrayList<>();
        SQLiteDatabase db = getReadableDatabase();

        String query = "SELECT * FROM tasks WHERE datetime(datetime) <= datetime('now') ORDER BY datetime DESC";
        Cursor cursor = db.rawQuery(query, null);

        if (cursor.moveToFirst()) {
            do {
                TaskModel task = new TaskModel();
                task.id = cursor.getInt(cursor.getColumnIndexOrThrow("id"));
                task.title = cursor.getString(cursor.getColumnIndexOrThrow("title"));
                task.description = cursor.getString(cursor.getColumnIndexOrThrow("description"));
                task.datetime = cursor.getString(cursor.getColumnIndexOrThrow("datetime"));
                task.status = cursor.getString(cursor.getColumnIndexOrThrow("status"));
                tasks.add(task);
            } while (cursor.moveToNext());
        }

        cursor.close();
        return tasks;
    }


    public List<TaskModel> getFutureTasks() {
        List<TaskModel> tasks = new ArrayList<>();
        SQLiteDatabase db = getReadableDatabase();

        String query = "SELECT * FROM tasks WHERE datetime(datetime) > datetime('now') ORDER BY datetime ASC";
        Cursor cursor = db.rawQuery(query, null);

        if (cursor.moveToFirst()) {
            do {
                TaskModel task = new TaskModel();
                task.id = cursor.getInt(cursor.getColumnIndexOrThrow("id"));
                task.title = cursor.getString(cursor.getColumnIndexOrThrow("title"));
                task.description = cursor.getString(cursor.getColumnIndexOrThrow("description"));
                task.datetime = cursor.getString(cursor.getColumnIndexOrThrow("datetime"));
                task.status = cursor.getString(cursor.getColumnIndexOrThrow("status"));
                tasks.add(task);
            } while (cursor.moveToNext());
        }

        cursor.close();
        return tasks;
    }


}

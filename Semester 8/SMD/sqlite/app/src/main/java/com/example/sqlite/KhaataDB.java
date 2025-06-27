package com.example.sqlite;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class KhaataDB {
    private final String DATABASE_NAME = "KhaataDB";
    private final String DATABASE_TABLE = "KhaataTable";
    private final int DATABASE_VERSION = 1;

    public static final String ROW_ID = "_id";
    public static final String ROW_TITLE = "_title";
    public static final String ROW_DESC = "_desc";
    public static final String ROW_PRICE = "_price";
    public static final String ROW_DATE = "_date";

    public Context dbContext;
    private DBhelper helper;
    private SQLiteDatabase ourDatabase;


    public KhaataDB (Context context){
        dbContext = context;
    }

    public void open ()
    {
        helper = new DBhelper(dbContext);
        ourDatabase = helper.getWritableDatabase();
    }

    public void close(){
        helper.close();
    }

    public long addNewKhaata ( String title, String desc, String date, String price ){
        ContentValues cv = new ContentValues();
        cv.put(ROW_TITLE, title);
        cv.put(ROW_DESC, desc);
        cv.put(ROW_DATE, date);
        cv.put(ROW_PRICE, price);

        return ourDatabase.insert(DATABASE_TABLE, null, cv);
    }

    public int removeKhaata( String rowID ){
        return ourDatabase.delete(DATABASE_TABLE, ROW_ID+"=?", new String[]{rowID});
    }

    public int updateKhaata(String rowID, String title, String desc, String date, String price){
        ContentValues cv = new ContentValues();
        cv.put(ROW_TITLE, title);
        cv.put(ROW_DESC, desc);
        cv.put(ROW_DATE, date);
        cv.put(ROW_PRICE, price);

        return ourDatabase.update(DATABASE_TABLE, cv, ROW_ID+"=?", new String[]{rowID});
    }

    public String getAllKhaatas() {
        String[] columns = new String[]{ROW_ID, ROW_TITLE, ROW_DESC, ROW_DATE, ROW_PRICE};

        Cursor c = ourDatabase.query(DATABASE_TABLE, columns, null, null, null, null, null);

        int indexID = c.getColumnIndex(ROW_ID);
        int indexTitle = c.getColumnIndex(ROW_TITLE);
        int indexDesc = c.getColumnIndex(ROW_DESC);
        int indexDate = c.getColumnIndex(ROW_DATE);
        int indexPrice = c.getColumnIndex(ROW_PRICE);

        String result = "";

        for (c.moveToFirst(); !c.isAfterLast(); c.moveToNext()) {
            result = result
                    + c.getString(indexID) + "\n"
                    + c.getString(indexTitle) + "\n"
                    + c.getString(indexDesc) + "\n"
                    + c.getString(indexDate) + "\n"
                    + c.getString(indexPrice) + "\n\n\n";
        }

        c.close();
        return result;
    }

    private class DBhelper extends SQLiteOpenHelper {

        public DBhelper( Context context ){
            super( context, DATABASE_NAME, null, DATABASE_VERSION, null );
        }

        @Override
        public void onCreate(SQLiteDatabase db) {

            /*CREATE TABLE KhaataDB (
                _id INTEGER PRIMARY KEY AUTOINCREMENT,
                _title TEXT NOT NULL,
                _desc TEXT NOT NULL,
                _date TEXT NOT NULL,
                _price INTEGER NOT NULL
                )
            */

            String query = "CREATE TABLE " + DATABASE_TABLE + " ( "
                    + ROW_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, "
                    + ROW_TITLE + " TEXT NOT NULL, "
                    + ROW_DESC + " TEXT NOT NULL, "
                    + ROW_DATE + " TEXT NOT NULL, "
                    + ROW_PRICE + " INTEGER NOT NULL )";

            db.execSQL(query);
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
            db.execSQL("DROP TABLE IF EXISTS " + DATABASE_TABLE);
            onCreate(db);
        }

    }

}

package com.example.jsonparsing;

import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONObject;

public class MainActivity extends AppCompatActivity {

    TextView displayAPIdata;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        displayAPIdata = findViewById(R.id.tvData);


        String url = "https://jsonplaceholder.typicode.com/todos/1";
        JsonObjectRequest json = new JsonObjectRequest(url, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject jsonObject) {

                try {
                    int userId = jsonObject.getInt("userId");
                    int id = jsonObject.getInt("id");
                    String title = jsonObject.getString("title");
                    Boolean isCompleted = jsonObject.getBoolean("completed");

                    String display = "User ID: " + userId + "\nID: " + id + "\nTitle: "
                            + title + "\nStatus: " + isCompleted;
                    displayAPIdata.setText(display);
                }
                catch (Exception e){
                    Toast.makeText(MainActivity.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                }

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError volleyError) {
                Toast.makeText(MainActivity.this, volleyError.toString(), Toast.LENGTH_SHORT).show();
            }
        }
        );

        RequestQueue reqQueue = Volley.newRequestQueue(this);
        reqQueue.add(json);
    }
}
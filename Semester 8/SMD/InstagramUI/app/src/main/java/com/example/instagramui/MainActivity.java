package com.example.instagramui;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.material.textfield.TextInputEditText;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;

public class MainActivity extends AppCompatActivity {

    TextView signup, fbLogin, signUp;
    TextInputEditText username, password;
    Button loginBtn;
    FirebaseAuth auth;
    FirebaseUser user;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        init();

        if(user!=null){
            //move the user to a home page or dashboard using intent
        }


        signup.setOnClickListener(v->{
            Intent i = new Intent(this, signup.class);
            startActivity(i);
        });

        loginBtn.setOnClickListener( v-> {
            String name = username.getText().toString().trim();
            String pass = password.getText().toString();

            if(TextUtils.isEmpty(name)){
                username.setError("Please enter the username");
                return;
            }
            if(TextUtils.isEmpty(pass)){
                password.setError("Please enter the password");
                return;
            }
            if(pass.length()<6){
                password.setError("Enter password greater than 6 letters");
                return;
            }

            auth.signInWithEmailAndPassword(name, pass)
                    .addOnSuccessListener(new OnSuccessListener<AuthResult>() {
                        @Override
                        public void onSuccess(AuthResult authResult) {
                            //navigate to a home page
                        }
                    })
                    .addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            Toast.makeText(MainActivity.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                        }
                    });
        });
    }
    private void init(){
        signup = findViewById(R.id.signup);
        fbLogin = findViewById(R.id.fb);
        signUp = findViewById(R.id.signup);
        username = findViewById(R.id.username);
        password = findViewById(R.id.password);
        loginBtn = findViewById(R.id.btn);
        auth = FirebaseAuth.getInstance();
        user = auth.getCurrentUser();
    }
}
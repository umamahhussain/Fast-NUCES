package com.example.instagramui;

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

public class signup extends AppCompatActivity {

    TextView logIn;
    TextInputEditText username, password, confirmPass;
    Button signupBtn;
    FirebaseAuth auth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_signup);

        init();

        signupBtn.setOnClickListener( v-> {
            String name = username.getText().toString().trim();
            String pass = password.getText().toString();
            String Cpass = confirmPass.getText().toString();

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
            if(!pass.equals(Cpass)){
                confirmPass.setError("Password Mismatch");
                return;
            }

            auth.createUserWithEmailAndPassword(name, pass)
                    .addOnSuccessListener(new OnSuccessListener<AuthResult>() {
                        @Override
                        public void onSuccess(AuthResult authResult) {
                            Toast.makeText(signup.this, "User Created", Toast.LENGTH_SHORT).show();
                        }
                    })
                    .addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            Toast.makeText(signup.this, e.getMessage(), Toast.LENGTH_SHORT).show();
                        }
                    });
        });
    }

    private void init(){
        logIn = findViewById(R.id.login);
        confirmPass = findViewById(R.id.confirmPass);
        username = findViewById(R.id.username);
        password = findViewById(R.id.password);
        signupBtn = findViewById(R.id.btnSignup);
        auth = FirebaseAuth.getInstance();
    }
}
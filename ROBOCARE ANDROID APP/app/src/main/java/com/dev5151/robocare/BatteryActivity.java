package com.dev5151.robocare;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import android.os.Bundle;
import android.widget.TextView;

import com.airbnb.lottie.LottieAnimationView;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class BatteryActivity extends AppCompatActivity {

    LottieAnimationView animationView;
    DatabaseReference myRef;
    private CardView cvBattery;
    TextView tvBattery;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_battery);


        animationView = findViewById(R.id.animationView);
        myRef = FirebaseDatabase.getInstance("https://fir-4d6dc.firebaseio.com/").getReference();
        tvBattery = findViewById(R.id.tvBattery);
        animationView.playAnimation();

        myRef.child("battery").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                tvBattery.setText(dataSnapshot.getValue() + " % ");
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });
    }
}

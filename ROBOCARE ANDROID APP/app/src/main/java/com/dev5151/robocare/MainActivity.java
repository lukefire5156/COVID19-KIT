package com.dev5151.robocare;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.cardview.widget.CardView;

import android.app.Service;
import android.content.Intent;
import android.graphics.Color;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.IBinder;
import android.provider.Settings;
import android.view.View;
import android.widget.TextView;

import com.airbnb.lottie.LottieAnimationView;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {
    DatabaseReference myRef;
    private CardView cvDistress, cvHeart, cvTemp, cvBattery;
    TextView tvHeart, tvTemp;
    LottieAnimationView animationView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myRef = FirebaseDatabase.getInstance("https://fir-4d6dc.firebaseio.com/").getReference();
        /*Intent i= new Intent(this, MyService.class);
        this.startService(i);
*/
        cvDistress = findViewById(R.id.cvDistress);
        cvTemp = findViewById(R.id.cvTemp);
        tvHeart = findViewById(R.id.tvHeart);
        tvTemp = findViewById(R.id.tvTemp);
        cvHeart = findViewById(R.id.cvHeart);
        cvBattery = findViewById(R.id.cvBattery);

        fetchData();

        cvHeart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, HeartActivity.class));
            }
        });

        cvTemp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, TempActivity.class));
            }
        });

        cvBattery.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this,BatteryActivity.class));
            }
        });
    }

    public void fetchData() {
        myRef.child("alert").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                if (dataSnapshot.getValue().equals("1")) {

                    cvDistress.setCardBackgroundColor(Color.RED);
                    MediaPlayer mediaPlayer = MediaPlayer.create(getApplicationContext(), Settings.System.DEFAULT_ALARM_ALERT_URI);
                    mediaPlayer.start();
                }
                myRef.child("alert").setValue("0");
                //animationView.pauseAnimation();
                // animationView.setVisibility(View.GONE);
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });

        myRef.child("heartBeat").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                tvHeart.setText(dataSnapshot.getValue() + " bpm ");
            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });

        myRef.child("temp").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot dataSnapshot) {
                tvTemp.setText(dataSnapshot.getValue() + " °F ");

            }

            @Override
            public void onCancelled(@NonNull DatabaseError databaseError) {

            }
        });

    }

}

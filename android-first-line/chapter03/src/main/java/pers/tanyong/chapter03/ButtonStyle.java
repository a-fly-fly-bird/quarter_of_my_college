package pers.tanyong.chapter03;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import pers.tanyong.chapter03.utils.DateUtil;

public class ButtonStyle extends AppCompatActivity {

    private TextView tv_view;
    private Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_button_style);
        tv_view = findViewById(R.id.textView);

        button = findViewById(R.id.button3);
        button.setOnClickListener(new MyOnClickListener(button));
    }

    public void doClick(View view){
        String desc = String.format("%s 您点击了按钮 %s", DateUtil.getNowTime(), ((Button)view).getText());
        tv_view.setText(desc);
        Log.e("hello", desc);
    }

    static class MyOnClickListener implements View.OnClickListener{

        private final Button button;

        public MyOnClickListener(Button button){
            this.button = button;
        }

        @Override
        public void onClick(View v) {
            this.button.setText("点击了该按钮");
        }
    }


}
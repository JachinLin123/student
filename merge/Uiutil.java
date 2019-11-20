/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cn.itmumu.util;

import java.awt.Dimension;
import java.awt.Image;
import java.awt.Toolkit;
import javax.swing.JFrame;

/**
 *
 * @author admin
 */
public class Uiutil {

    private Uiutil() {

    }

    public static void setFrameImage(JFrame jf) {
        Toolkit tk = Toolkit.getDefaultToolkit();
        Image i = tk.getImage("src\\cn\\itmumu\\resource\\user.jpg");
        jf.setIconImage(i);
    }
    
    public static void setFrameImage(JFrame jf,String imagename ) {
        Toolkit tk = Toolkit.getDefaultToolkit();
        Image i = tk.getImage("src\\cn\\itmumu\\resource\\"+imagename);
        jf.setIconImage(i);
    }
    
    public static void setFrameCenter(JFrame jf){
        Toolkit tk = Toolkit.getDefaultToolkit();
        Dimension d= tk.getScreenSize();
        double screenWidth = d.getWidth();
        double screenHeight = d.getHeight();
        int frameWidth = jf.getWidth();
        int frameHeight = jf.getHeight();
        int width = (int)(screenWidth-frameWidth)/2;
        int height = (int)(screenHeight-frameHeight)/2;
        
        jf.setLocation(width, height);
        
    }

}

package HomeWorks;

import java.util.Scanner;

/**
 * 智能农机具有型号（specific）
 * 标定马力（horsepower,>=0）
 * 重量（weight,大于1.2吨小于等于3吨）
 * 外观长度尺寸（size,>30cm且<=120cm）
 * 运行速度（speed,>=0km/h且<=120km/h）等信息，
 * 有四个车轮，每个车轮有尺寸(size,[20,110])和胎压(psi,[0,19])。
 * 请按照上述类涉及一段程序代码模拟一辆智能农机并实现换轮胎功能，并能够体现方法重载。
 *
 * @author it_mumu
 */
public class Exp4_itmumu {
    public static void main(String[] args) {
        /**
         * 创建农机对象
         */
        IntelligentMachine sc = new IntelligentMachine();
        /**
         * 设置型号
         */
        sc.setSpecific("TD123");
        /**
         * 马力值
         */
        sc.setHorsepower(65.2f);
        /**
         * 重量
         */
        sc.setWeight(1.5f);
        /**
         * 速度
         */
        sc.setSpeed(120);
        /**
         * 外观尺寸
         */
        sc.setLength(60);
        /**
         * 输出农机的基本信息
         */
        System.out.println(" I am a " +sc.getSpecific()+" machine ,"+"my horsepower is "+ sc.getHorsepower() +
                ",speed is "+sc.getSpeed()+"千米每时,length is "+sc.getLength()+"cm ,weight is "+sc.getWeight()+"t .");

        /**
         * 对农机的轮胎尺寸赋值
         */
        sc.setSize();
        /**
         * 输出四个轮子的尺寸大小信息
         */
        System.out.println("输出所有轮子尺寸的信息:");
        System.out.println("the left front size "+sc.size[0]+"\n"+"the right front size "+
                sc.size[1]+"\n"+"the left behind size "+sc.size[2]+"\n"+"the right behind size "+sc.size[3]);
        /**
         * 对农机轮胎胎压的设置
         */
        sc.setPsi();
        System.out.println("输出所有轮子胎压的信息:");
        System.out.println("the left front psi "+sc.psi[0]+"\n"+"the right front psi "+
                sc.psi[1]+"\n"+"the left behind psi "+sc.psi[2]+"\n"+"the right behind psi "+sc.psi[3]);
        System.out.println("*********  1:换一个轮胎  *********");
        System.out.println("*********  2:换两个轮胎  *********");
        System.out.println("*********  3:换三个轮胎  *********");
        System.out.println("*********  4:换四个轮胎  *********");
        Scanner sr = new Scanner(System.in);
        System.out.println("请输入你的选择:");
        int choose = sr.nextInt();
        System.out.println("请输入你要换轮子的编号，0:左前轮,1:右前轮,2:左后轮,3:右后轮。");
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        switch (choose){
            case 1:
                a = sr.nextInt();
                sc.change(a);break;
            case 2:
                a = sr.nextInt();
                b = sr.nextInt();
                sc.change(a,b);break;
            case 3:
                a = sr.nextInt();
                b = sr.nextInt();
                c = sr.nextInt();
                sc.change(a,b,c);break;
            case 4:
                a = sr.nextInt();
                b = sr.nextInt();
                c = sr.nextInt();
                d = sr.nextInt();
                sc.change(a,b,c,d);break;
                default:
                    System.out.println("你输入的数据有误!");
        }
        System.out.println("更换完成!");
        System.out.println("the left front size "+sc.size[0]+"\n"+"the right front size "+
                sc.size[1]+"\n"+"the left behind size "+sc.size[2]+"\n"+"the right behind size "+sc.size[3]);
        System.out.println("the left front psi "+sc.psi[0]+"\n"+"the right front psi "+
                sc.psi[1]+"\n"+"the left behind psi "+sc.psi[2]+"\n"+"the right behind psi "+sc.psi[3]);
    }
}

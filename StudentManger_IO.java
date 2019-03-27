package ArrayListTest;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class StudentManger_IO {
    public static void main(String[] args) throws IOException {

        String fileName = "student.txt";
        ArrayList<Student> array = new ArrayList<Student>();
        while (true) {
            System.out.println("-----欢迎来到学生管理系统------");
            System.out.println("1:查看所有学生");
            System.out.println("2:添加学生");
            System.out.println("3:修改学生");
            System.out.println("4:删除学生");
            System.out.println("5:退出系统");
            System.out.println("请输入你的选择：");
            Scanner sc = new Scanner(System.in);
            String choicestring = sc.nextLine();
            switch (choicestring) {
                case "1":
                    Studentdallstudent(fileName);
                    break;
                case "2":
                    addStudent(fileName);
                    break;
                case "3":
                    deleteStudent(fileName);
                    break;
                case "4":
                    xiugaiStudent(fileName);
                    break;
                case "5":
                default:
                    System.out.println("谢谢你的使用");
                    System.exit(0);
                    break;
            }
        }
    }
    //从文件中读数据到集合

    public static void readData(String FileName, ArrayList<Student> array) throws IOException {
        String fileName = "student.txt";
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String line;
        while ((line = br.readLine()) != null) {
            String[] datas = line.split(",");
            Student s = new Student();
            s.setId(datas[0]);
            s.setName(datas[1]);
            s.setAge(datas[2]);
            s.setAdress(datas[3]);
            array.add(s);
        }
        br.close();
    }

    //从集合中写数据到文件

    public static void writeData(String FileName, ArrayList<Student> array) throws IOException {
        String fileName = "student.txt";
        BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
        for (int i = 0; i < array.size(); i++) {
            Student s = array.get(i);
            StringBuilder sb = new StringBuilder();
            sb.append(s.getId()).append(",").append(s.getName()).append(",").append(s.getAge()).append(",").append(s.getAdress());
            bw.write(sb.toString());
            bw.newLine();
            bw.flush();
        }
        bw.close();
    }

    public static void Studentdallstudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        if (array.size() == 0) {
            System.out.println("不好意思，当前没有学生信息供你查询！");
            return;
        }
        System.out.println("学号\t\t姓名\t年龄\t居住地");
        for (int x = 0; x < array.size(); x++) {
            Student s = array.get(x);
            System.out.println(s.getId() + "\t" + s.getName() + "\t" + s.getAge() + "\t" + s.getAdress());
        }

    }

    public static void addStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入学生学号");
        String id = sc.nextLine();
        System.out.println("请输入学生姓名");
        String name = sc.nextLine();
        System.out.println("请输入学生年龄");
        String age = sc.nextLine();
        System.out.println("请输入学生的家庭住址");
        String adress = sc.nextLine();
        Student s = new Student();
        s.setId(id);
        s.setName(name);
        s.setAge(age);
        s.setAdress(adress);
        array.add(s);
        writeData(fileName,array);
        System.out.println("添加学生成功");
    }

    public static void deleteStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你要删除学生的学号");
        String id = sc.nextLine();
        int index = -1;
        for (int x = 0; x < array.size(); x++) {
            Student s = array.get(x);
            if (s.getId().equals(id)) {
                index = x;

                break;
            }
        }
        if (index == -1) {
            System.out.println("不好意思，没有此号学生！");
        } else {
            array.remove(index);
            writeData(fileName,array);
            System.out.println("删除学生成功");
        }
    }

    public static void xiugaiStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入你要修改学生的学号");
        String id = sc.nextLine();
        int index = -1;
        for (int x = 0; x < array.size(); x++) {
            Student s = array.get(x);
            if (s.getId().equals(id)) {
                index = x;
                break;
            }
        }
        if (index == -1) {
            System.out.println("不好意思，你修改的学生的信息不存在");
        } else {
            System.out.println("请输入学生新姓名");
            String name = sc.nextLine();
            System.out.println("请输入学生新年龄");
            String age = sc.nextLine();
            System.out.println("请输入学生的新家庭住址");
            String adress = sc.nextLine();
            Student s = new Student();
            s.setName(name);
            s.setAge(age);
            s.setAdress(adress);
            array.set(index, s);
            writeData(fileName,array);
            System.out.println("修改学生信息成功");
        }

    }
}
package ArrayListTest;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class StudentManger_IO {
    public static void main(String[] args) throws IOException {

        String fileName = "student.txt";
        ArrayList<Student> array = new ArrayList<Student>();
        while (true) {
            System.out.println("-----��ӭ����ѧ������ϵͳ------");
            System.out.println("1:�鿴����ѧ��");
            System.out.println("2:���ѧ��");
            System.out.println("3:�޸�ѧ��");
            System.out.println("4:ɾ��ѧ��");
            System.out.println("5:�˳�ϵͳ");
            System.out.println("���������ѡ��");
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
                    System.out.println("лл���ʹ��");
                    System.exit(0);
                    break;
            }
        }
    }
    //���ļ��ж����ݵ�����

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

    //�Ӽ�����д���ݵ��ļ�

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
            System.out.println("������˼����ǰû��ѧ����Ϣ�����ѯ��");
            return;
        }
        System.out.println("ѧ��\t\t����\t����\t��ס��");
        for (int x = 0; x < array.size(); x++) {
            Student s = array.get(x);
            System.out.println(s.getId() + "\t" + s.getName() + "\t" + s.getAge() + "\t" + s.getAdress());
        }

    }

    public static void addStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("������ѧ��ѧ��");
        String id = sc.nextLine();
        System.out.println("������ѧ������");
        String name = sc.nextLine();
        System.out.println("������ѧ������");
        String age = sc.nextLine();
        System.out.println("������ѧ���ļ�ͥסַ");
        String adress = sc.nextLine();
        Student s = new Student();
        s.setId(id);
        s.setName(name);
        s.setAge(age);
        s.setAdress(adress);
        array.add(s);
        writeData(fileName,array);
        System.out.println("���ѧ���ɹ�");
    }

    public static void deleteStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("��������Ҫɾ��ѧ����ѧ��");
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
            System.out.println("������˼��û�д˺�ѧ����");
        } else {
            array.remove(index);
            writeData(fileName,array);
            System.out.println("ɾ��ѧ���ɹ�");
        }
    }

    public static void xiugaiStudent(String fileName) throws IOException {
        ArrayList<Student> array = new ArrayList<Student>();
        readData(fileName,array);
        Scanner sc = new Scanner(System.in);
        System.out.println("��������Ҫ�޸�ѧ����ѧ��");
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
            System.out.println("������˼�����޸ĵ�ѧ������Ϣ������");
        } else {
            System.out.println("������ѧ��������");
            String name = sc.nextLine();
            System.out.println("������ѧ��������");
            String age = sc.nextLine();
            System.out.println("������ѧ�����¼�ͥסַ");
            String adress = sc.nextLine();
            Student s = new Student();
            s.setName(name);
            s.setAge(age);
            s.setAdress(adress);
            array.set(index, s);
            writeData(fileName,array);
            System.out.println("�޸�ѧ����Ϣ�ɹ�");
        }

    }
}
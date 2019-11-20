package HomeWorks;

public class IntelligentMachine {
    /**
     * 智能农机的型号
     */
    private String specific;
    /**
     * 智能农机的标定马力>=0
     */
    private float horsepower;
    /**
     * 智能农机重量，以吨作单位。
     */
    private float weight;
    /**
     * 智能农机的外观尺寸，单位厘米
     */
    private int length;
    /**
     * 智能农机的速度，单位千米每时
     */
    private int speed;
    /**
     * 轮胎的尺寸大小，单位厘米
     */
    public int size[] = new int[4];
    /**
     * 轮胎的胎压
     */
    public float psi[] = new float[4];

    public String getSpecific() {
        return specific;
    }

    public void setSpecific(String specific) {
        this.specific = specific;
    }

    public float getHorsepower() {
        return horsepower;
    }

    public void setHorsepower(float horsepower) {
        if (horsepower >= 0)
            this.horsepower = horsepower;
        else
            this.horsepower = -1;


    }

    public float getWeight() {
        return weight;
    }

    public void setWeight(float weight) {
        if (weight >= 1.2 && weight <= 3)
            this.weight = weight;
        else
            this.weight = -1;

    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        if (length >= 30 && length <= 120)
            this.length = length;
        else
            this.length = -1;

    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        if (speed >= 0 && speed <= 120)
            this.speed = speed;
        else
            this.speed = -1;
    }

    public void setSize() {
        /**
         * 左前轮尺寸
         */
        this.size[0] = 40;
        /**
         * 右前轮尺寸
         */
        this.size[1] = 40;
        /**
         * 左后轮尺寸
         */
        this.size[2] = 60;
        /**
         * 右后轮尺寸
         */
        this.size[3] = 60;
    }

    public void setPsi() {
        /**
         * 左前轮胎压
         */
        this.psi[0] = 9;
        /**
         * 右前轮胎压
         */
        this.psi[1] = 10;
        /**
         * 左后轮胎压
         */
        this.psi[2] = 11;
        /**
         * 右后轮胎压
         */
        this.psi[3] = 13;
    }

    /**
     * @param a 换一个轮胎
     */
    public void change(int a) {
        this.size[a] = 45;
        this.psi[a] = 11.5f;
    }

    /**
     * 换两个轮胎
     *
     * @param a
     * @param b
     */
    public void change(int a, int b) {
        this.size[a] = 45;
        this.psi[a] = 11.5f;
        this.size[b] = 45;
        this.psi[b] = 11.6f;
    }

    /**
     * 换三个轮胎
     *
     * @param a
     * @param b
     * @param c
     */
    public void change(int a, int b, int c) {
        this.size[a] = 45;
        this.psi[a] = 11.5f;
        this.size[b] = 45;
        this.psi[b] = 11.6f;
        this.size[c] = 80;
        this.psi[c] = 15f;
    }

    /**
     * 换四个轮胎
     *
     * @param a
     * @param b
     * @param c
     * @param d
     */
    public void change(int a, int b, int c, int d) {
        this.size[a] = 45;
        this.psi[a] = 11.5f;
        this.size[a] = 45;
        this.psi[a] = 11.6f;
        this.size[a] = 80;
        this.psi[a] = 15f;
        this.size[a] = 80;
        this.psi[a] = 15.1f;
    }


}

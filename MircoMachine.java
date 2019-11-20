package mircomachine;

/**
 * 创建微机类
 */
public class MircoMachine {
    public enum Position {
        nLeftHead, nLeftRear, nRightHead, nRightRear;
    }
    private final int MAX_GAP = 20;
    private Wheel[] wheels;
    private Door[] doors;

    /**
     * 初始化轮子和门
     */
    public MircoMachine() {
        wheels = new Wheel[4];
        doors = new Door[4];
    }

    /**
     * 安装门到具体位置
     * @param position
     * @param door
     */
    public void mountDoor(Position position, Door door) {
        if (position.ordinal() < doors.length) {
            doors[position.ordinal()] = door;
        }
    }

    /**
     * 安装轮子到具体位置
     * @param position
     * @param wheel
     */
    public void mountWheel(Position position, Wheel wheel) {
        if (position.ordinal() < wheels.length) {
            wheels[position.ordinal()] = wheel;
        }
    }

    /**
     * 检查能否启动
     * @return
     */
    public String start() {
        int i = checkDoors();
        int j = checkWheels();
        if(i==-1&&j==-1){
            return "something gone wrong:Door and Wheel";
        }
        if(j==-1)
            return "轮胎未安装完全!";
        if(i==-1)
            return "车门未安装完全!";
        if (i==-2) {
            return "车门未关闭，请检查车门！";
        }
        if (j==-2) {
            return "胎压不平衡，请先测量胎压!";
        }
        return "I'm ready to go";
    }

    /**
     * 检查门的状况
     * @return
     */
    private int checkDoors() {
        /**
         * 用于判断们处于什么转态
         */
        int i = 0;
        for (Door door : doors) {
            if (door == null ) {
                i=-1;
            }
            else if(door.getStateFlag() == Door.StateFlag.opened){
                i=-2;
            }
        }
        return i;
    }

    /**
     * 检查轮子的状况
     * @return
     */
    private int checkWheels() {
        /**
         * 用于判断轮子处于何种转态
         */
        int f = 0;
        for (Wheel wheel : wheels) {
            if (wheel == null) {
                f=-1;
                break;
            }
            for (int i = 0; i < wheels.length / 2; i++) {
                for (int j = i + 1; j < wheels.length; j++)
                    if (Math.abs(wheels[i].getPsi() - wheels[j].getPsi()) > MAX_GAP) {
                        f=-2;
                    }
            }
        }
        return f;
    }
}

/**
 * 创建轮子类
 */
class Wheel {
    private float psi;

    public float getPsi() {
        return psi;
    }

    public void setPsi(float psi) {
        this.psi = psi > 0 ? psi : 0;
    }

    public Wheel(float psi) {
        setPsi(psi);
    }

    public Wheel() {
        this(40);
    }
}

/**
 * 创建门类
 */
class Door {
    public enum StateFlag {
        opened, closed;
    }

    private StateFlag stateFlag = StateFlag.opened;

    public Door(StateFlag stateFlag) {
        this.stateFlag = stateFlag;
    }

    public Door() {
        this(StateFlag.opened);
    }

    public StateFlag getStateFlag() {
        return stateFlag;
    }

    public void setStateFlag(StateFlag stateFlag) {
        this.stateFlag = stateFlag;
    }
}

package mircomachine;

public class Exp5_itmumu {
    public static void main(String[] args) {
        /**
         * 创建微机对象
         */
        MircoMachine m = new MircoMachine();
        /**
         * 给微机安装轮子
         */
        m.mountWheel(MircoMachine.Position.nLeftHead, new Wheel());
        m.mountWheel(MircoMachine.Position.nLeftRear, new Wheel());
        m.mountWheel(MircoMachine.Position.nRightHead, new Wheel());
        m.mountWheel(MircoMachine.Position.nRightRear, new Wheel());
       /**
        *给微机安装门
        */
        m.mountDoor(MircoMachine.Position.nLeftHead, new Door(Door.StateFlag.opened));
        m.mountDoor(MircoMachine.Position.nLeftRear, new Door(Door.StateFlag.closed));
        m.mountDoor(MircoMachine.Position.nRightHead, new Door(Door.StateFlag.closed));
        m.mountDoor(MircoMachine.Position.nRightRear, new Door(Door.StateFlag.closed));
        /**
         * 检查微机的启动状况
         */
        System.out.println(m.start());


    }
}

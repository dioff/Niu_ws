## 一、Niubility战队寒假ROS比赛及培训资料

![Static Badge](https://img.shields.io/badge/ROS-Melodic-green)![Static Badge](https://img.shields.io/badge/Ubuntu-18.04-%23FF9900)

> 本仓库基于ROS-Melodic版本完成Niubility寒假对内赛题二及ROS培训资料

## 二、安装依赖

本仓库基于 ROS，请自行安装 ROS-Melodic-desktop 

安装依赖：

- Gampping
- Teb-local-planner
- Driver_base
- Controller

```bash
sudo apt-get install ros-melodic-driver-base

sudo apt-get install ros-melodic-gazebo-ros-control
sudo apt-get install ros-melodic-effort-controllers
sudo apt-get install ros-melodic-joint-state-controller

sudo apt-get install ros-melodic-teb-local-planner

sudo apt-get install ros-melodic-slam-gmapping
```

ps. 若有依赖缺少请与我沟通

## 三、编译功能包

```bash
git clone git@github.com:dioff/Niu_ws.git
cd Niu_ws/
catkin_make -j8
source devel/setup.bash # 自行添加进入环境变量
```

## 四、运行模型文件

```bash
roslaunch car_gazebo car_gazebo.launch
```

若出现模型位置错乱的情况可以重新进入

查看rostopic

```bash
rostopic list
# 以下是话题信息
ncut@ubuntu:~$ rostopic list
/cam
/cam/compressed
/cam/compressed/parameter_descriptions
/cam/compressed/parameter_updates
/cam/compressedDepth
/cam/compressedDepth/parameter_descriptions
/cam/compressedDepth/parameter_updates
/cam/theora
/cam/theora/parameter_descriptions
/cam/theora/parameter_updates
/camera_info
/clock
/cmd_vel
/gazebo/link_states
/gazebo/model_states
/gazebo/parameter_descriptions
/gazebo/parameter_updates
/gazebo/set_link_state
/gazebo/set_model_state
/imu
/joint_states
/odom
/parameter_descriptions
/parameter_updates
/rosout
/rosout_agg
/scan
/tf
/tf_static
```

## 五、功能包介绍

文件结构：
├── car_gazebo
├── car_map
├── teb_local_planner-melodic-devel
└── teleop_twist_keyboard

功能包中已自带建图程序demo，可自行修改参数进行建图

```bash
roslaunch car_map liu_gmapping.launch
```

功能包中内置开源键盘控制程序，可自行查看使用方法，若程序不运行请给python程序加权限

```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

## 六、更新情况

- 2024.1.30 05：19 第一次更新仓库
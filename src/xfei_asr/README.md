**ROS与语音交互-编写科大讯飞语音SDK的ROS包**

**说明**

- ROS软件包xfei_asr是集成自科大讯飞的linux的DEMO
- 介绍xfei_asr的安装和使用
- 介绍如何发布文字主题转变成语音播放
- 介绍如何录音并转变成文字输出，并发布主题

要求：

- 需要到科大讯飞网站注册帐号(只需要APPID)，[访问科大讯飞网站](http://www.xfyun.cn/)
- 安装语音库：sudo apt-get install libasound2-dev (录音)

安装依赖：

```
$ sudo apt-get update
$ sudo apt-get install libasound2-dev 
```

下载：

- 从github上clone
- 放入自己相对应得功能包

修改CMakelist.txt：

```
target_link_libraries(
   asr_sample
   ${catkin_LIBRARIES} 
   /home/ubu/catkin_ws/src/xfei_asr/lib/libmsc.so -ldl -pthread
 )
```

- 找到所有的`target_link_libraries`，修改`/home/ubu/catkin_ws`为你自己的工作空间`/home/xxxx/catkin_ws`

修改代码：

- 找到 *.c 和*.cpp文件中查找appid = 58249817，替换58249817为你自己申请的APPID.
- `同时更换自己下载sdk里面的libmsc.so到对应的xfei_asr/lib/libmsc.so` 

编译：

```
$ cd ~/catkin_ws/
$ catkin_make
```

文件结构：

```
ubu@ubu:~/xf-ros/xfei_asr$ tree
.
├── CMakeLists.txt
├── include
│   ├── formats.h
│   ├── linuxrec.h
│   ├── msp_cmn.h
│   ├── msp_errors.h
│   ├── msp_types.h
│   ├── qisr.h
│   ├── qtts.h
│   ├── speech_recognizer.h
│   └── xfei_asr
├── lib
│   └── libmsc.so
├── package.xml
├── README.md
└── src
    ├── asr_sample.c
    ├── gm_continuous_digit.abnf
    ├── iat_publish_speak.cpp
    ├── iat_record.c
    ├── iat_sample.c
    ├── linuxrec.c
    ├── msc
    │   ├── b0c4f74dc1f1bd969732c841500eff0d
    │   │   ├── u.data
    │   │   └── urec.data
    │   └── msc.cfg
    ├── sch_speak.c
    ├── sch_text.c
    ├── source.txt
    ├── speech_recognizer.c
    ├── tts_sample.c
    ├── tts_sample.wav
    ├── tts_subscribe_speak.cpp
    ├── userwords.txt
    └── wav
        ├── iflytek01.wav
        ├── iflytek02.wav
        └── weather.pcm
```

使用说明：

1. 进入包的src源目录（`所有的rosrun要在源目录执行，因为一些相对路径的目录在src目录下`）

```
$ roscd xfei_asr/src 
```

1. 执行SDK DEMO, 目前可用：asr_sample、iat_sample、iat_record

- 命令：

```
$ rosrun xfei_asr asr_sample
```

- 效果：（读取src/wav/iflytek01.wav, 并识别出文字）

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-1.png)

- 命令：

```
$ rosrun xfei_asr iat_sample
```

- 效果:

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-2.png)

- 命令：

```
$ rosrun xfei_asr iat_record
```

- 效果：

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-3.png)

1. 运行ROS DEMO，目前可用：tts_subscribe_speak、iat_publish_speak

```
$ rosrun xfei_asr  tts_subscribe_speak
$ rosrun xfei_asr  iat_publish_speak
```

1. tts_subscribe_speak详细使用：

- 新开终端1：

```
$ roscore 
```

- 新开终端2：

```
$ rosrun xfei_asr  tts_subscribe_speak
```

- 新开终端3：

```
$ rostopic pub xfwords std_msgs/String "测试ncnynl.com"
```

- 效果：

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-4.png)

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-5.png)

1. iat_publish_speak详细使用：

- 新开终端1：

```
$ roscore 
```

- 新开终端2: (订阅xfwakeup主题，发布xfspeech主题和xfwords主题)

```
$ rosrun xfei_asr  iat_publish_speak
```

- 新开终端3：（xfspeech主题是录音专成的文字）

```
$ rostopic echo /xfspeech
```

- 新开终端4：（xfwords主题是错误提示文字）

```
$ rostopic echo /xfwords
```

- 新开终端5：（xfwakeup主题是唤醒功能，每发一次就可以录音一次。）

```
$ rostopic pub xfwakeup std_msgs/String "ok"
```

- 效果：

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-6.png)

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-7.png)

![请输入图片描述](http://images.ncnynl.com/ros/2016/xf-ros-8.png)
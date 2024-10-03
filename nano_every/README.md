# arduino nano every

## 設定

```
cd libs/ros_lib/
rosrun rosserial_arduino make_libraries.py .
```

```
pip install platformio
```

## 書き込み

```
pio run -t upload -e jointstate_6servo4
```

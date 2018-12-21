## Log Display

Display log data of flight.

开发环境：	Qt 5.8.0 MSVC2013版本。

Qt库：QSqlite进行数据库操作，QtCharts（Qt5.7版本后加入Qt模块）进行绘图

### 运行效果图

![log1]()

### 程序结构

Log相关的程序都在/LogDisplay/中

- LogWidget：log数据显示的主页面，选择并导入log文件，在页面上选择log数据项进行绘图显示

- LogAnalysis：解析log文件，将log数据存储在数据库表中

- chartView：继承自QChartView，可自定义鼠标、键盘事件

- Callout：tooltip框，鼠标悬浮在chart中的线上时，显示当前点的数据

- 其他：log数据是二进制，按头文件中定义的结构存储。读取log文件时要按照这些头文件（basic_types.h， sdfiles.h，message.h）定义的结构进行解析       

### 程序流程

1. LogWidget中选择并打开log文件
2. LogAnalysis解析log文件，将log数据分类存储在数据库对应的表中
3. 在LogWidget左侧的QTreeWidget中选择item，就会查询数据库对应表中的数据，在TableView中显示数据，并在chartView中绘图显示

#### tips

SQLite数据库本质上来讲就是一个磁盘上的文件，所以一切的数据库操作其实都会转化为对文件的操作，在向数据库写入大量log数据时，频繁的文件操作会极大地影响数据库存取的速度。

于是我们通过事务来提高数据库的读写速度。事务的基本原理是：数据库管理系统会把要执行的sql语句存储到内存当中，commit()的时候一次性全部执行所有内存中的数据库。

```c++
db.transaction(); // 开始启动事务
... // 执行数据库操作
db.commit() // 提交事务
```
Qt 正则实现
===


####正则代码如下:

````
  QString str = "OTDR-ACTIVE::1:2:PORT=10,POWER=10;OTDR-ACTIVE::1:2:PORT=10,POWER=10;";
  QRegExp rx("OTDR-ACTIVE::1:2:PORT=(\\d+),POWER=\\1;");
  QStringList qStringList;
  int pos = 0;
  while ((pos = rx.indexIn(str, pos)) != -1) {
    qStringList << rx.cap(1);
    pos += rx.matchedLength();
  }
````
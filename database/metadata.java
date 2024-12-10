//Examining Database Metadata - 데이터베이스 메타데이터 확인
DatabaseMetaData md = con.getMetaData();

System.out.println(
    "Name: " + md.getDriverName() +
    "version: " + md.getDriverVersion();

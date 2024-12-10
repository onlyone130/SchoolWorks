//경고 및 예외처리
try{
    stmt = con.createStatment();
    warning = con.getWarnings();
    while(warning != null){
        warning = warning.getNextWarning();
    }
    con.clearWarnings();
    stmt.executeUpdate(queryString);
    warning = con.getWarnings();
    ...
}
catch(SQLException SQLe){

}

Connection con = DriverManager.getConnection(url,"login","pass");
Statment stmt = con.createStatement();
String query = "SELECT name, rating FROM Sailors";
ResultSet rs = stmt.executeQuery(query);

try{
    while(rs.next()){
        String s = rs.getString("name");
        int n = rs.getInt("rating");
        System.out.println(s+" "+n);
   }
   catch(SQLException ex){
    System.out.println(ex.getMessage()+ex.getSQLState()+ex.getErrorCode());
   }
}
)

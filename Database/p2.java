import java.sql.*;
//write a program that connects to your database and then prints the names and colors of
//all boats in the boats table.
 
public class embedded {
 
	public static void main(String[] argv) {
 
		try {
 
			Class.forName("org.postgresql.Driver");
 
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
			return;
 
		}
 
		Connection connection = null;
 
		try {
 
			connection = DriverManager.getConnection(
					"jdbc:postgresql://dbclass.cs.pdx.edu:5432/f15ddb22", "f15ddb22", "khc10825"); 
		} catch (SQLException e) {
			e.printStackTrace();
			return;
 
		}
 
		if (connection != null) {
			try {
				Statement st = connection.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
				boolean status = st.execute("SELECT * FROM boats");
				if (status) {
					ResultSet rset = st.getResultSet();
					ResultSetMetaData meta = rset.getMetaData();

					int nColumns = meta.getColumnCount();
					for (int i = 1; i <= nColumns; i++){ 
						String columnName = meta.getColumnLabel(i);
						System.out.print(columnName + " ");
					}
					System.out.println();
					while (rset.next()){
						for (int i = 1; i <= nColumns; i++){
							Object val = rset.getObject(i);
							System.out.print(val + " ");
						}
						System.out.println();
						int sid = rset.getInt("sid");
						if (sid == 22) {
							rset.updateInt("rating",10000);
							rset.updateRow();
						}
					}
					rset.close();
				}

				
				connection.close();

			} catch (SQLException e) {
				e.printStackTrace();
			}
		} else {
			System.out.println("Failed to make connection!");
		}
	}
 
}

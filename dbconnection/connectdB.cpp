#include <iostream>
#include <mysqlx/xdevapi.h>

using namespace mysqlx;
using namespace std;


int main() {
    Session session("localhost", 3306, "root", "chazard10.3");
    Schema schema = session.getSchema("cpp");
    RowResult result = schema.getTable("teachers").select("id", "first_name", "last_name", "email").execute();
    for (Row row : result.fetchAll()) {
        cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl;
    }
    session.close();
    return 0;
}

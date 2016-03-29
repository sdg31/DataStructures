using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Common;
using System.Data.SqlClient;

namespace spoop
{
    static class DbConnectionExtension
    {
        public static IEnumerable<T> Read<T>( DbConnection db, string sql )
            where T:class, IEquatable<T>, IEnumerable<T>, new()
        {
            db = new SqlConnection( sql );
            SqlCommand command = new SqlCommand( sql, db as SqlConnection );
            SqlDataReader reader = command.ExecuteReader();
            db.Open();
            int i = 0;
            while( reader.Read() )
            {
                if( reader[i] is T )
                    yield return reader[i] as T;
                ++i;
            }

            db.Dispose();
        }
    }
}

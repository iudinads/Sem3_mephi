#include <iostream>
#include "Graphes/UndirectedGraph.h"
#include "Graphes/DirectedGraph.h"
#include "Methods/ShortestPathDi.cpp"
#include "Methods/ShortestPathUnDi.cpp"
#include <ctime>

using namespace std;


int GetRand(int min, int max)
{
	int num = min + rand() % (max - min + 1);
	return num;
}


int PathUnDi()
{
    //my manual test

    cout << endl;
    cout << "my manual test" << endl;
    cout << endl;
    UndirectedGraph g1;
    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addVertex(4);
    g1.addVertex(5);
    g1.addVertex(6);
    g1.addVertex(7);
    g1.addVertex(8);
    g1.addVertex(9);
    g1.addVertex(10);
    g1.addEdge(1, 2, 3);
    g1.addEdge(2, 3, 2);
    g1.addEdge(3, 4, 2);
    g1.addEdge(4, 6, 1);
    g1.addEdge(6, 7, 3);
    g1.addEdge(6, 8, 4);
    g1.addEdge(7, 10, 2);

    for (int v1 : g1.getVertices())
    {
        cout << "Neighbors of vertex " << v1 << " : ";
        for (int v : g1.getNeighbors(v1)) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int v2 = 1; v2 < 9; v2++)
    {
        for (int v10 = v2 + 1; v10 < 10; v10++)
        {
            if (g1.hasEdge(v2, v10)){
            cout << "Weight of the edge between " << v2 << " - " << v10 << " : " << g1.getWeight(v2, v10) ;
            cout << endl;
            }
        }
    }

    cout << endl;
    clock_t time_req1;
    time_req1 = clock();
    cout << "Shortest path from vertex 1 to vertex 10" << " : " << "{ "  << shortestPath2(g1, 1, 10) << endl;
    time_req1 = clock() - time_req1;
    cout << "time to find the shortest path: " << (float)time_req1/CLOCKS_PER_SEC << " seconds.\n";
    cout << "Shortest path from vertex 1 to vertex 4" << " : " << "{ "  << shortestPath2(g1, 1, 4) << endl;
    cout << "Shortest path from vertex 5 to vertex 1" << " : " << "{ "  << shortestPath2(g1, 1, 5) << endl;
    cout << endl;   


    // your manual test
    cout << "your manual test" << endl;
    cout << endl;
    UndirectedGraph g2;
    int size;
    cout << "how many vertices do you want to have? " << endl;
    while (!(cin >> size ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int val;
    for (int i2 = 0; i2 < size; i2++)
    {
        cout << "enter the " << i2 << " vertix ";
        cin >> val;
        g2.addVertex(val);
    }

    int val2;
    int val3;
    int val7;
    cout << endl;
    cout << "to stop enter 0" << endl;
    do
    {
        cout << "first vertix in the edge: ";
        cin >> val2;
        if (val2 == 0)
        {
            break;
        }
        cout << "the last vertix in the edge: ";
        cin >> val3;
        cout << "enter the weight (>1) between " << val2 << " - " << val3 <<  " : ";
        cin >> val7;
        g2.addEdge(val2, val3, val7);
    } while (val2 != 0);
    
    cout << endl;


    for (int v3 : g2.getVertices())
    {
        cout << "Neighbors of vertex " << v3 << " : ";
        for (int v4 : g2.getNeighbors(v3)) {
            cout << v4 << " ";
        }
        cout << endl;
    }
    cout << endl;
     
     for (int f3 = 1; f3 < size; f3++)
    {
        for (int f4 = 0; f4 <= size; f4++)
        {
            if (g2.hasEdge(f3, f4)){
            cout << "Weight of the edge between " << f3 << " - " << f4 << " : " << g2.getWeight(f3, f4) ;
            cout << endl;
            }
        }
    }

    cout<< endl;

    int val4;
    int val5;
    cout << "between what vertices you want to find path?" << endl;

    cout << "enter the first vertix in the path: ";
    cin >> val4;
    cout << "enter the last vertix in the path: ";
    cin >> val5;
    cout << "Shortest path from vertex " << val4 << " to vertex " << val5 << " : " << " { " << shortestPath2(g2, val4, val5) << endl;

    cout << endl;


    return 0;
}

int PathDi()
{
    //my manual test

    cout << endl;
    cout << "my manual test" << endl;
    cout << endl;
    DirectedGraph g1;
    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addVertex(4);
    g1.addVertex(5);
    g1.addVertex(6);
    g1.addVertex(7);
    g1.addVertex(8);
    g1.addVertex(9);
    g1.addVertex(10);
    g1.addEdge(1, 2, 3);
    g1.addEdge(2, 3, 2);
    g1.addEdge(3, 4, 2);
    g1.addEdge(4, 6, 1);
    g1.addEdge(6, 7, 3);
    g1.addEdge(6, 8, 4);
    g1.addEdge(7, 10, 2);

    for (int v1 : g1.getVertices())
    {
        cout << "Neighbors of vertex " << v1 << " : ";
        for (int v : g1.getNeighbors(v1)) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int v2 = 1; v2 < 9; v2++)
    {
        for (int v10 = v2 + 1; v10 < 10; v10++)
        {
            if (g1.hasEdge(v2, v10)){
            cout << "Weight of the edge between " << v2 << " - " << v10 << " : " << g1.getWeight(v2, v10) ;
            cout << endl;
            }
        }
    }
    cout << endl;   
    size_t time_req2;
    time_req2 = clock();
    cout << "Shortest path from vertex 1 to vertex 10:" << " { " << shortestPath1(g1, 1, 10) << endl;   
    time_req2 = clock() - time_req2;
    cout << "time to find the shortest path: " << (float)time_req2/CLOCKS_PER_SEC << " seconds.\n";
    cout << "Shortest path from vertex 1 to vertex 4:" << " { " << shortestPath1(g1, 1, 4) << endl;
    cout << "Shortest path from vertex 1 to vertex 5:" << " { " << shortestPath1(g1, 1, 5) << endl;

    // your manual test
    cout << "!now your manual test! " << endl;
    cout << endl;
    DirectedGraph g2;
    int size;
    cout << endl;
    cout << "how many vertices do you want to have? " << endl;
    while (!(cin >> size ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int val;
    for (int i2 = 0; i2 < size; i2++)
    {
        cout << "enter the " << i2 << " vertix ";
        while (!(cin >> val ))
        {
            cout << "wrong input :(" << endl;
            cout << "try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        g2.addVertex(val);
    }

    int val2;
    int val3;
    int val7;
    cout << endl;
    cout << "to stop enter 0" << endl;
    cout << endl;
    do
    {
        cout << "first vertix in the edge: ";
        while (!(cin >> val2 ))
        {
            cout << "wrong input :(" << endl;
            cout << "try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (val2 == 0)
        {
            break;
        }
        else
        {
            cout << "the last vertix in the edge: ";
            while (!(cin >> val3 ))
            {
                cout << "wrong input :(" << endl;
                cout << "try again : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "enter yhe weight between " << val2 << " - " << val3 <<  " : ";
            while (!(cin >> val7 ))
            {
                cout << "wrong input :(" << endl;
                cout << "try again : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            g2.addEdge(val2, val3, val7);
        }
    } while (val2 != 0);
    cout << endl;
    for (int v3 : g2.getVertices())
    {
        cout << "Neighbors of vertex " << v3 << " : ";
        for (int v4 : g2.getNeighbors(v3)) {
            cout << v4 << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int f = 1; f < size; f++)
    {
        for (int f1 = 0; f1 <= size; f1++)
        {
            if (g2.hasEdge(f, f1)){
            cout << "Weight of the edge between " << f << " - " << f1 << " : " << g2.getWeight(f, f1) ;
            cout << endl;
            }
        }
    }

    cout << endl;

    int val4;
    int val5;
    cout << "between what vertices you want to find path?" << endl;

    cout << "enter the first vertix in the path: ";
    while (!(cin >> val4 ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "enter the last vertix in the path: ";
    while (!(cin >> val5 ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    size_t time_req4;
    time_req4 = clock();
    cout << "Shortest path from vertex " << val4 << " to vertex " << val5 << " : " << " { "<< shortestPath1(g2, val4, val5) << endl;
    time_req4 = clock() - time_req4;
    cout << "time to find the shortest path: " << (float)time_req4/CLOCKS_PER_SEC << " seconds.\n";
    cout << endl;


    return 0;
}



int StructDi()
{
    cout << endl;
    DirectedGraph g3;
    int size;
    cout << endl;
    cout << "how many vertices do you want to have? " << endl;
    while (!(cin >> size ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int val;
    for (int i2 = 0; i2 < size; i2++)
    {
        cout << "enter the " << i2 << " vertix ";
        while (!(cin >> val ))
        {
            cout << "wrong input :(" << endl;
            cout << "try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        g3.addVertex(val);
    }

    int val2;
    int val3;
    int val7;
    cout << endl;
    cout << "to stop enter 0" << endl;
    cout << endl;
    do
    {
        cout << "first vertix in the edge: ";
        while (!(cin >> val2 ))
        {
            cout << "wrong input :(" << endl;
            cout << "try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (val2 == 0)
        {
            break;
        }
        else
        {
            cout << "the last vertix in the edge: ";
            while (!(cin >> val3 ))
            {
                cout << "wrong input :(" << endl;
                cout << "try again : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "enter yhe weight between " << val2 << " - " << val3 <<  " : ";
            while (!(cin >> val7 ))
            {
                cout << "wrong input :(" << endl;
                cout << "try again : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            g3.addEdge(val2, val3, val7);
        }
    } while (val2 != 0);
    cout << endl;
    for (int v3 : g3.getVertices())
    {
        cout << "Neighbors of vertex " << v3 << " : ";
        for (int v4 : g3.getNeighbors(v3)) {
            cout << v4 << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int f = 1; f < size; f++)
    {
        for (int f1 = 0; f1 <= size; f1++)
        {
            if (g3.hasEdge(f, f1)){
            cout << "Weight of the edge between " << f << " - " << f1 << " : " << g3.getWeight(f, f1) ;
            cout << endl;
            }
        }
    }

    cout << endl;

    int choice;
    cout << "what do you want to do? " << endl;
    cout << "1 - remove vertex" << endl;
    cout << "2 - remove edge" << endl;
    cin >> choice;
    int vert;
    if (choice == 1)
    {
        cout << "enter vertex to remove: ";
        cin >> vert;
        g3.removeVertex(vert);
        for (int v5 : g3.getVertices())
        {
            cout << "Neighbors of vertex " << v5 << " : ";
            for (int v6 : g3.getNeighbors(v5)) {
                cout << v6 << " ";
            }
            cout << endl;
        }
        cout << endl;

        
    }
    int edge1;
    int edge2;    
    if (choice == 2)
    {
        cout << "enter the first vertex in the edge to remove: ";
        cin >> edge1;
        cout << "enter the second vertex in the edge to remove: ";
        cin >> edge2;
        g3.removeEdge(edge1, edge2);
        for (int v7 : g3.getVertices())
        {
            cout << "Neighbors of vertex " << v7 << " : ";
            for (int v8 : g3.getNeighbors(v7)) {
                cout << v8 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}


int StructUnDi()
{
    cout << endl;
    UndirectedGraph g3;
    int size;
    cout << "how many vertices do you want to have? " << endl;
    while (!(cin >> size ))
    {
        cout << "wrong input :(" << endl;
        cout << "try again : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int val;
    for (int i2 = 0; i2 < size; i2++)
    {
        cout << "enter the " << i2 << " vertix ";
        cin >> val;
        g3.addVertex(val);
    }

    int val2;
    int val3;
    int val7;
    cout << endl;
    cout << "to stop enter 0" << endl;
    do
    {
        cout << "first vertix in the edge: ";
        cin >> val2;
        if (val2 == 0)
        {
            break;
        }
        cout << "the last vertix in the edge: ";
        cin >> val3;
        cout << "enter the weight (>1) between " << val2 << " - " << val3 <<  " : ";
        cin >> val7;
        g3.addEdge(val2, val3, val7);
    } while (val2 != 0);
    
    cout << endl;


    for (int v3 : g3.getVertices())
    {
        cout << "Neighbors of vertex " << v3 << " : ";
        for (int v4 : g3.getNeighbors(v3)) {
            cout << v4 << " ";
        }
        cout << endl;
    }
    cout << endl;
     
     for (int f3 = 0; f3 < size; f3++)
    {
        for (int f4 = f3 + 1; f4 <= size; f4++)
        {
            if (g3.hasEdge(f3, f4)){
            cout << "Weight of the edge between " << f3 << " - " << f4 << " : " << g3.getWeight(f3, f4) ;
            cout << endl;
            }
        }
    }

    cout<< endl;

    int choice1;
    cout << "what do you want to do? " << endl;
    cout << "1 - remove vertex" << endl;
    cout << "2 - remove edge" << endl;
    cin >> choice1;
    int vert;
    if (choice1 == 1)
    {
        cout << "enter vertex to remove: ";
        cin >> vert;
        g3.removeVertex(vert);
        for (int v5 : g3.getVertices())
        {
            cout << "Neighbors of vertex " << v5 << " : ";
            for (int v6 : g3.getNeighbors(v5)) {
                cout << v6 << " ";
            }
            cout << endl;
        }
        cout << endl;

        
    }
    int edge1;
    int edge2;    
    if (choice1 == 2)
    {
        cout << "enter the first vertex in the edge to remove: ";
        cin >> edge1;
        cout << "enter the second vertex in the edge to remove: ";
        cin >> edge2;
        g3.removeEdge(edge1, edge2);
        cout << endl;
        for (int v7 : g3.getVertices())
        {
            cout << "Neighbors of vertex " << v7 << " : ";
            for (int v8 : g3.getNeighbors(v7)) {
                cout << v8 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;

}
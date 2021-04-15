/*
  Application on Depth-First Search Algorithm
*/

using System;

namespace Family_DFS
{

    class Frontire {
        //init length -1
        int top = -1;
        //nodes length 15
        Node[] nodes = new Node[15];
        public bool isFull() => top == nodes.Length - 1;
        public bool isEmpty() => top == -1;

        public void add(Node newNode) {
            if (!isFull())
                nodes[++top] = newNode;
            else throw new Exception("Frontier is Full");
        }

        //Remove Node (LIFO).
        public Node remove() {
            if (isEmpty())
                throw new Exception("Frontier is Empty");
            
            return nodes[top--];
        }
        //Check if frontire contanis node with specific name
        public bool containsState(string state) {
            if (isEmpty()) throw new Exception("Frontire is Empty");

            for(int i = 0; i <= top; i++) {
                if (nodes[i].state == state) return true;
            }
                
            return false;
        }
    }
    class Node {
        // state hold the name
        public string state;
        //children 
        public Node[] childs;
        //node parent
        public Node parent = null;
        //Add name, parent
        public Node(string name, Node p) {
            state = name;
            parent = p;
            return;
        }

    }



    class Program
    {
        static void Solve(Node start, string toFind) {

            Console.Clear();

            // Adding init State to Frontire
            int explored = 0;
            Frontire f = new Frontire();
            f.add(start);

            //Loop
            while (true)
            {
                //If Frontire is empty No solution
                if (f.isEmpty()) throw new Exception("No solution!");
              
                //Remove a node from Frontire
                Node explore = f.remove();
                explored += 1;
                Console.WriteLine("Exploring Node: {0}", explore.state);

                //Checking for the name we want
                if (explore.state == toFind)
                {
                    Console.WriteLine("{0} explored", explored);
                    while (explore != null)
                    {
                        if(explore.parent == null)
                          Console.Write("{0}\n", explore.state);
                        else
                          Console.Write("{0} ==> ", explore.state);

                        explore = explore.parent;
                    }
                    return;
                }
                //Expend node and add to frontire
                if (explore.childs != null)
                    foreach (Node c in explore.childs)
                        f.add(c);
            }


        }
        static void Main(string[] args)
        {
            try
            {
            string answer = "";

            //Take input
            Console.Write("Grandfather name: ");
            string name = Console.ReadLine();
            Node s = new Node(name, null);
            Console.Write("How many Children? ");
            int len = Int32.Parse(Console.ReadLine());
            s.childs = new Node[len];
            for (int i = 0; i < len; i++)
            {
                Console.Write("Enter Grandfather's son {1} name: ", name, i + 1);
                string c_name = Console.ReadLine();
                Node c_node = new Node(c_name, s);
                Console.Write("How many childs does {0} have? ", c_name);

                int c_len = Int32.Parse(Console.ReadLine());
           
                if (c_len > 0)
                {
                    c_node.childs = new Node[c_len];
                    for (int j = 0; j < c_len; j++)
                    {
                        Console.Write("Enter {0}'s  Child {1} name: ", c_name, j + 1);
                        string c_cname = Console.ReadLine();
                        c_node.childs[j] = new Node(c_cname, c_node);
                    }
                    s.childs[i] = c_node;
                }
            }
            do
            {
                Console.Write("Enter Name to search for: ");
                string name_toFind = Console.ReadLine();
                //Pass init state and name we want to solve func
                Solve(s, name_toFind);
                Console.Write("Search for another name? yes/no:  ");
                answer = Console.ReadLine();
            } while (answer == "yes");

            }catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                return;
            }
        } 
    }
}

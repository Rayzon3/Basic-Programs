//Undirected Graph
import java.util.*;

public class graph{
   
    private Map<Integer, ArrayList<Integer>> adjListMap;
   
    public graph(int vertices){
        adjListMap = new HashMap<Integer, ArrayList<Integer>>();
        for(int i = 1; i <= vertices; i++){
            ArrayList<Integer> neighbours = new ArrayList<Integer>();
            adjListMap.put(i, neighbours);
        }
    }

    public void addEdge(int v, int w){
        if(v > adjListMap.size()){
            return;
        }
        (adjListMap.get(v)).add(w);
        (adjListMap.get(w)).add(v);
    }

    public ArrayList<Integer> getNeighbours(int v){
        if(v > adjListMap.size()){
            return null;
        }
        return new ArrayList<Integer>(adjListMap.get(v));
    }

    public static void main(String args[]) {
        int count = 1, src, des;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter the number of vertices and edges:");
        int v = input.nextInt();
        int e = input.nextInt();

        graph gObj = new graph(v);

        System.out.println("Enter edges in format <Source> <Destination>");
        while(count <= e){
            src = input.nextInt();
            des = input.nextInt();
            gObj.addEdge(src, des);
            count++;
        }
        System.out.println("The adjacency list for the graph is : \n");
        for(int i = 1; i <= v; i++){
            System.out.print(i + "->");
            ArrayList<Integer> edgeList = gObj.getNeighbours(i);
            for(int j = 1;;j++){
                if(j != edgeList.size()){
                    System.out.print(edgeList.get(j - 1) + " -> ");
                }
                else{
                    System.out.print(edgeList.get(j - 1));
                    break;
                }
            }
            System.out.println();
        }

    }
}

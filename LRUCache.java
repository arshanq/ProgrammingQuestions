public class LRUCache {
    
    private HashMap<Integer, Node> map = new HashMap<Integer, Node>();
    private Node headOfTheList = null ;
    private int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    private void deleteNode(Node node) {
        map.remove(node.getKey());
        if(node.getPreviousNode() == null && node.getNextNode() == null) {
            headOfTheList = null;
        }
        else if(node.getPreviousNode() == null && node.getNextNode() != null) {
            node.getNextNode().setPreviousNode(null);
            headOfTheList = node.getNextNode();
        }
        else if(node.getNextNode() == null && node.getPreviousNode() != null) {
            node.getPreviousNode().setNextNode(null);
        }
        else {
            node.getPreviousNode().setNextNode(node.getNextNode());
            node.getNextNode().setPreviousNode(node.getPreviousNode());
        }
    }
    
    private void insertNode(Node node) {
        map.put(node.getKey(), node);
        if(headOfTheList == null) headOfTheList = node;
        else {
            headOfTheList.setPreviousNode(node);
            node.setNextNode(headOfTheList);
            node.setPreviousNode(null);
            headOfTheList = node;
        }
    }
    
    private void printList() {
        Node node = headOfTheList;
        System.out.println("Printing list");
        while(node != null) {
            System.out.println("Key: "+node.getKey() + " Value: " + node.getValue());
            node = node.getNextNode();
        }
        System.out.println("Ending list");
    }
    
    public int get(int key) {
    //    System.out.println("Get key: " + key);
        if(map.containsKey(key)) {
            Node node = map.get(key);
            deleteNode(node);
            insertNode(node);
     //       printList();
            return node.getValue();
        }
        return -1;
    }
    
    public void set(int key, int value) {
      //  System.out.println("Set key: " + key + " value: " + value);
        if(map.containsKey(key)) {
            Node node  = map.get(key);
            node.setValue(value);
            deleteNode(node);
            insertNode(node);
       //     printList();
            return ;
        }
         if(map.size() == this.capacity) {
             if(capacity == 1) {
                 deleteNode(headOfTheList);
                 map.remove(key);
             }else {
                Node lruNode = headOfTheList;
                for(int i = 1; i <= this.capacity-1;i++) {
                    lruNode = lruNode.getNextNode();
                }
                deleteNode(lruNode);
             }
        }
        Node node = new Node();
        node.setKey(key);
        node.setValue(value);
        insertNode(node);
     //   printList();
    }
    
    public static class Node {
        private int value;
        private int key;
        private Node previousNode = null;
        private Node nextNode = null;
        
        public void setKey(int key){
            this.key = key;
        }
        
        public void setValue(int value) {
            this.value = value;
        }
        
        public void setPreviousNode(Node preNode) {
            this.previousNode = preNode;
        }
        
        public void setNextNode(Node nextNode) {
            this.nextNode = nextNode;
        }
        
        public int getKey() {
            return this.key;
        }
        
        public int getValue() {
            return this.value;
        }
        
        public Node getPreviousNode() {
            return this.previousNode;
        }
        
        public Node getNextNode() {
            return this.nextNode;
        }
    }
}

public class LRUCache {
    
    private HashMap<Integer, Node> map = new HashMap<Integer, Node>();
    private Node headOfTheList = null ;
    private int capacity;
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if(map.containsKey(key)) {
            Node node = map.get(key);
            if(node.getPreviousNode() != null) {
               node.getPreviousNode().setNextNode(node.getNextNode());
               node.setNextNode(headOfTheList);
               headOfTheList = node;
            }
            return node.getValue();
        }
        return -1;
    }
    
    public void set(int key, int value) {
         if(map.size() == this.capacity) {
             if(capacity == 1) {
                 map.remove(headOfTheList.getKey());
                 headOfTheList = null;
             }else {
                Node node = headOfTheList;
                for(int i = 1; i <= this.capacity-2;i++) {
                    node = node.getNextNode();
                }
                Node lruNode = node.getNextNode();
                map.remove(lruNode.getKey());
                node.setNextNode(null);   
             }
        }
        Node node = new Node();
        node.setKey(key);
        node.setValue(value);
        node.setNextNode(headOfTheList);
        headOfTheList = node;
        map.put(key, node);
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

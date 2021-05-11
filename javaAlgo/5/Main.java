package DocumentWordBinaryTree;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.nio.file.LinkOption;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import static java.util.stream.Collectors.toMap;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please provide a valid file path as an argument");
            System.exit(-1);
        }

        Path path = Paths.get(args[0]);

        // check for txt file as an input in the argument       
        if (!isTextFile(path)) {
            System.out.println("Only txt files are supported, please provide a link for a txt file");
            System.exit(-1);
        }

        // check if the file or directory exists in the system and also if it is readable
        if (!Files.exists(path, LinkOption.NOFOLLOW_LINKS) && !Files.isReadable(path) && !Files.isRegularFile(path, LinkOption.NOFOLLOW_LINKS)) {
            System.out.println("ERROR: the file does not exist  \n "
                    + "OR the file is not accessible \n"
                    + "OR path is invalid");
            System.exit(-1);
        }

        wordFreqCount(path);

    }

    private static boolean isTextFile(Path path) {

        String pathString = path.toString();
        String txtString = pathString.substring(pathString.length() - 4);
        return txtString.equals(".txt");

    }

    private static void wordFreqCount(Path path) {

        try {
            String content = new String(Files.readAllBytes(path), Charset.forName("UTF-8"));
            Stream<String> stream = Stream.of(content.toLowerCase().split("\\s+")).parallel();
            Map<String, Long> wordFreq = stream.collect(Collectors.groupingBy(String::toString, Collectors.counting()));
            if (wordFreq.isEmpty()) {
                System.out.println("Unfortunately your text file is empty!!\nPlease provide a text file with some content");
                System.exit(-1);
            }
            Map<String, Long> sortedWordFreq = wordFreq.entrySet().stream()
                    .sorted(Entry.comparingByValue())
                    .collect(toMap(Entry::getKey, Entry::getValue,
                            (e1, e2) -> e1, LinkedHashMap::new));

            createBinaryTree(sortedWordFreq);

        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void createBinaryTree(Map<String, Long> map) {

        LinkedList<Node> nodeList = new LinkedList<>();
        for (Map.Entry<String, Long> entry : map.entrySet()) {
            Node node = new Node(entry.getKey(), entry.getValue());
            nodeList.add(node);
        }
        int verticalIteration = getVerticalIteration(nodeList.size());

        List<Node> replacedNodeList = new LinkedList<>();    
        for (int i = 0; i < verticalIteration; i++) {

            for (int j = 0; j < nodeList.size() - 1; j += 2) {
                Node nodeLeft = nodeList.get(j);
                Node nodeRight = nodeList.get(j + 1);

                Node newNode = new Node("Lvl:" + (i + 2), nodeLeft.getValue() + nodeRight.getValue(), nodeLeft, nodeRight);
                nodeLeft.setParent(newNode);
                nodeRight.setParent(newNode);

                replacedNodeList.add(newNode);
            }

            if (nodeList.size() % 2 == 1) {
                replacedNodeList.add(nodeList.get(nodeList.size() - 1));
            }
            Collections.sort(replacedNodeList, (o1, o2) -> o1.getValue().compareTo(o2.getValue()));
            nodeList.clear();
            nodeList.addAll(replacedNodeList);
            replacedNodeList.clear();

        }
        
        Node binaryTree = nodeList.get(0);
        binaryTree.print();

    }

    private static int getVerticalIteration(int arraysize) {

        boolean isLastIteration = false;
        int currentArraySize = arraysize;
        int iterationCount = 0;

        while (isLastIteration == false) {
            iterationCount++;
            currentArraySize = (currentArraySize % 2 == 1) ? (currentArraySize /= 2) + 1 : (currentArraySize /= 2);
            isLastIteration = (currentArraySize == 1);
        }

        return iterationCount;

    }

}

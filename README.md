# bedrock_solution
1. Publisher frequency varied by setting the node_rate param in the launch file.
2. Random float values published between 0 and 1 over /pub topic.
3. Publishing can be started or stopped using service calls (true or false) on the /toggle server.
4. Unit tests to check get() method of publisher state.

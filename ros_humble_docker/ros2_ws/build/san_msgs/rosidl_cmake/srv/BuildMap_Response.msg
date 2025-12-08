
# Response
bool success
string message


# # Build Map
# ros2 service call /build_map san_msgs/srv/BuildMap "{
#   command: 1
# }"

# # Finish Map
# ros2 service call /build_map san_msgs/srv/BuildMap "{
#   command: 3,
#   map_name: 'map_250402'
# }"
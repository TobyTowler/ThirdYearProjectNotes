import utm # source: https://github.com/JayArghArgh/surveytoolbox
from surveytoolbox.bdc import bearing_distance_from_coordinates # source: https://github.com/JayArghArgh/surveytoolbox
from surveytoolbox.SurveyPoint import NewSurveyPoint
from surveytoolbox.config import DIST_2D, BEARING, EASTING, NORTHING, ELEVATION 

#from Sample_Co_ordinates import PATH_UTM
from Pathing.Sample_Co_ordinates import PATH_UTM


def generate_CMDs(path_coordinates = []):
    """Returns a list of the generated commands that the robot 
    can execute using the UTM path coordinates.

    Args:
        path_coordinates (list, optional): The UTM formatted path that we want to generate Commands for so that the robot can traverse the path. Defaults to [].

    Returns:
        generated_CMDs: Returns a list of the generated commands that the robot can execute to follow the path.
    """        
    # check if any path_coordinates was passed in the function
    if path_coordinates is None or len(path_coordinates) < 1: # path_coordinates list must have at least 2 element
        return
    # 
    def get_distance_and_bearing(p1, p2):
        """function to get the distance and bearing between two UTM co-ordinates

        Args:
            p1 (Sting[]): UMT Coordinate of the starting/current point 
            p2 (_type_): UTM Coordinate of the end/target point

        Returns:
            tuple: Returns the calculated distance and bearing from the starting point to the end point
        """            
        # convert the input coordinates to SurveyPoints
        surv_p1 = NewSurveyPoint("start_point")
        surv_p2 = NewSurveyPoint("end_point")
        surv_p1.set_vertex(
            {
                EASTING: p1[0],
                NORTHING: p1[1],
                ELEVATION: 0 # We don't care about elevation, as we are looking at working in a 2D plane
            })
        surv_p2.set_vertex(
            {
                EASTING: p2[0],
                NORTHING: p2[1],
                ELEVATION: 0 # We don't care about elevation, as we are looking at working in a 2D plane
            })

        # calculate the distance and bearing between the two survey points
        calc = bearing_distance_from_coordinates(
            surv_p1.get_vertex(),
            surv_p2.get_vertex())

        # return the distance and bearing
        return calc[DIST_2D], calc[BEARING]

    # generated CMDs that will be returned
    generated_CMDs = []
    
    # get the first UTM path coordinate and get the distance, and the bearing, to the next path_coordinates in the sequence
    seq_len = len(path_coordinates)
    print("Seq Length: ", seq_len)
    for i in range(0, seq_len-1):
        # get the distance and bearing from one point to the next point
        dist, bearing = get_distance_and_bearing(
            path_coordinates[i],
            path_coordinates[i+1]
            )
        print (f"From: {path_coordinates[i]}, To: {path_coordinates[i+1]}")

        #round the distance and bearing to 2 dp
        dist = round(dist, 2)
        bearing = round(bearing, 2)

        # TODO: Calculate the best direction to rotate by to get the shortest adn fastest rotation        
        # altBearing = bearing - 360
        # if abs(altBearing) < bearing:
        #     bearing = altBearing

        # create a rotate to bearing CMD (cmdChar, rotSpeed, bearing)
        cmd = ['b', 100, bearing]
        generated_CMDs.append(cmd)
        print(f"CMD: {cmd}")
        # create a move distance CMD
        milliDistance = dist * 1000
        cmd = ['d', 100, milliDistance] # 'd 200 {0}'.format(milliDistance)
        generated_CMDs.append(cmd)
        print(f"CMD: {cmd}")

    return generated_CMDs


def convert_lat_long_to_UTM(lat_long_list):
    """Converts a list of lat/long coordinates to UTM coordinates

    Args:
        lat_long_list (String[]): List of the lat/long coordinates to convert to a UTM coordinates

    Returns:
        String: returns the converted UTM coordinates list
    """        
    # list to store the UTM coordinates that will be returned
    UTM_coordinates = []
    # convert the latitude and longitude passed list to UTM coordinates
    for lat_long in lat_long_list:
        UTM_coordinates.append(utm.from_latlon(lat_long[0], lat_long[1]))

    return UTM_coordinates



# file main method
def main():
    path_coordinates = PATH_UTM
    generated_CMDs = generate_CMDs(path_coordinates)
    
    # print the generators path coordinates
    # print("UTM Path Co-ordinates:")
    # print(path_coordinates)

    # print the generators generated CMDs
    print("Generated CMDs:")
    for cmd in generated_CMDs:
        print(cmd)

if __name__ == "__main__":
    main()
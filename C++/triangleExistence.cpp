bool triangleExistence(std::vector<int> sides) {
//check if a triangle is possible or not
    if(sides[0] + sides[1] >= sides[2] && sides[1] + sides[2] >= sides[0] && sides[2] + sides[0] >= sides[1])
        return true;
    return false;
}

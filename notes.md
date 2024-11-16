## Sample Doxygen-style comments in C++

```
/**
 * @class Vector3D
 * @brief A class representing a 3D vector with basic vector operations.
 *
 * This class implements a mathematical vector in 3D space with common
 * vector operations like addition, subtraction, dot product, and cross product.
 *
 * @author John Doe
 * @version 1.0
 * @date 2024-11-16
 *
 * @note Thread-safe: No
 * @bug No known bugs
 *
 * @see Matrix3D
 * @see Point3D
 */
class Vector3D {
public:
    /**
     * @brief Default constructor.
     * Initializes vector to (0,0,0).
     */
    Vector3D();

    /**
     * @brief Parameterized constructor.
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param z The z-coordinate
     *
     * @throws std::invalid_argument if any parameter is NaN
     */
    Vector3D(double x, double y, double z);

private:
    /** @brief The x-coordinate of the vector */
    double x_;
    
    /** @brief The y-coordinate of the vector */
    double y_;
    
    /** @brief The z-coordinate of the vector */
    double z_;
};
```
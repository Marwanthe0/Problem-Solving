import numpy as np
import matplotlib.pyplot as plt

# 1. Set the number of random points to generate
num_points = 10000

# 2. Generate random x and y coordinates between -1 and 1
# np.random.uniform creates an array of random numbers evenly distributed
x = np.random.uniform(-1, 1, num_points)
y = np.random.uniform(-1, 1, num_points)

# 3. Calculate the distance squared from the origin (0,0)
# Pythagorean theorem: r^2 = x^2 + y^2
distance_squared = x**2 + y**2

# Create a boolean mask (True/False) for points that fall inside the circle (radius <= 1)
inside_circle = distance_squared <= 1

# 4. Calculate the estimation of Pi
# Count how many points are 'True' (inside the circle)
points_inside = np.sum(inside_circle)
pi_estimate = 4 * (points_inside / num_points)

# 5. Visualization Setup
plt.figure(figsize=(8, 8))

# Plot points OUTSIDE the circle (using the ~ operator to invert the mask)
plt.scatter(
    x[~inside_circle],
    y[~inside_circle],
    color="red",
    s=2,
    alpha=0.6,
    label="Outside Circle",
)

# Plot points INSIDE the circle
plt.scatter(
    x[inside_circle],
    y[inside_circle],
    color="blue",
    s=2,
    alpha=0.6,
    label="Inside Circle",
)

# Draw the exact boundary of the circle for visual clarity
circle = plt.Circle((0, 0), 1, color="black", fill=False, linewidth=2)
plt.gca().add_patch(circle)

# Format the plot to make it look nice and perfectly square
plt.xlim(-1.05, 1.05)
plt.ylim(-1.05, 1.05)
plt.gca().set_aspect(
    "equal"
)  # Ensures the square and circle don't stretch into rectangles/ellipses
plt.title(
    f"Monte Carlo Estimation of Pi\nTotal Points: {num_points} | Estimated Pi: {pi_estimate:.5f} | Actual: {np.pi:.5f}"
)
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.legend(loc="upper right")
plt.grid(True, linestyle="--", alpha=0.5)

# 6. Display the final plot
plt.show()

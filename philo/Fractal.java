import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Fractal extends JPanel {
    private static  int MAX_ITERATIONS = 1000;
    private static  double MIN_X = -2.5;
    private static  double MAX_X = 1.0;
    private static  double MIN_Y = -1.0;
    private static  double MAX_Y = 1.0;
    private static  int WIDTH = 800;
    private static  int HEIGHT = 600;
    private static  double ZOOM_FACTOR = 1.5;
    private static  Color[] COLORS = {
        Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.BLUE, Color.MAGENTA
    };

    private BufferedImage image;

    public Fractal() {
        image = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        drawFractal();
    }

    private void drawFractal() {
        double x, y, xNew, yNew, zReal, zImag;
        int iterations;
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                x = MIN_X + (MAX_X - MIN_X) * i / WIDTH;
                y = MIN_Y + (MAX_Y - MIN_Y) * j / HEIGHT;
                zReal = x;
                zImag = y;
                iterations = 0;
                while (iterations < MAX_ITERATIONS && zReal * zReal + zImag * zImag < 4.0) {
                    xNew = zReal * zReal - zImag * zImag + x;
                    yNew = 2.0 * zReal * zImag + y;
                    zReal = xNew;
                    zImag = yNew;
                    iterations++;
                }
                if (iterations == MAX_ITERATIONS) {
                    image.setRGB(i, j, Color.BLACK.getRGB());
                } else {
                    int colorIndex = iterations % COLORS.length;
                    image.setRGB(i, j, COLORS[colorIndex].getRGB());
                }
            }
        }
    }

    public void zoomIn(int x, int y) {
        double centerX = MIN_X + (MAX_X - MIN_X) * x / WIDTH;
        double centerY = MIN_Y + (MAX_Y - MIN_Y) * y / HEIGHT;
        double width = (MAX_X - MIN_X) / ZOOM_FACTOR;
        double height = (MAX_Y - MIN_Y) / ZOOM_FACTOR;
        MIN_X = centerX - width / 2;
        MAX_X = centerX + width / 2;
        MIN_Y = centerY - height / 2;
        MAX_Y = centerY + height / 2;
        drawFractal();
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(image, 0, 0, null);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Mandelbrot Set");
        Fractal fractal = new Fractal();
        frame.getContentPane().add(fractal);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

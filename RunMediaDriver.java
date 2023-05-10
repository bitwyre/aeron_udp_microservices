import io.aeron.driver.MediaDriver;

public class RunMediaDriver {
    public static void main(String[] args) {
        MediaDriver driver = MediaDriver.launch();
    }
}
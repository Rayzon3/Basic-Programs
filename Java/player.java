import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;
import java.util.LinkedList;

class musicPlayer {

    Long currentFrame;
    Clip clip;

    String status;
    static int i = 0;
    

    AudioInputStream audioInputStream;
    static String filePath;

    public musicPlayer() throws UnsupportedAudioFileException, IOException, LineUnavailableException {

        // create AudioInputStream object
        audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());

        // create clip reference
        clip = AudioSystem.getClip();

        // open audioInputStream to the clip
        clip.open(audioInputStream);

        clip.loop(Clip.LOOP_CONTINUOUSLY);
    }
    

    public static void main(String[] args) {

        File f1 = null;

        try {
            
            LinkedList<String> LLObj = new LinkedList<String>();
            LLObj.push("/Users/rahulbhardwaj/Documents/Dev/Player/songs/Charlie Puth - Dangerously.wav");
            LLObj.push("/Users/rahulbhardwaj/Documents/Dev/Player/songs/Eagles - Hotel California.wav");
            LLObj.push("/Users/rahulbhardwaj/Documents/Dev/Player/songs/Charlie Puth - Hard on Yourself.wav");
            LLObj.push("/Users/rahulbhardwaj/Documents/Dev/Player/songs/Britney Spears - Toxic.wav");

            

            filePath = LLObj.get(i);
            if(i == 0){
                f1 = new File(LLObj.get(i));
                System.out.println("## Now Playing " + f1.getName() + " ##");
            }
            musicPlayer audioPlayer = new musicPlayer();

            audioPlayer.play();
            Scanner sc = new Scanner(System.in);

            while (true) {
                System.out.println("1. Pause");
                System.out.println("2. Resume");
                System.out.println("3. Restart");
                System.out.println("4. Jump to specific time");
                System.out.println("5. Play next song");
                System.out.println("6. Play previous song");
                System.out.println("7. Exit");
                int c = sc.nextInt();
                if (c == 5){
                    audioPlayer.stop();
                    i++;
                    f1 = new File(LLObj.get(i));
                    System.out.println("## Now Playing " + f1.getName() + " ##");
                    musicPlayer.main(args);
                }
                else if (c == 6) {
                    audioPlayer.stop();
                    i--;
                    f1 = new File(LLObj.get(i));
                    System.out.println("## Now Playing " + f1.getName() + " ##");
                    musicPlayer.main(args);
                }
                audioPlayer.gotoChoice(c);
            }
           
        }

        catch (Exception ex) {
            System.out.println("Error with playing sound.");
            ex.printStackTrace();

        }
    }

    private void gotoChoice(int c) throws IOException, LineUnavailableException, UnsupportedAudioFileException {
        switch (c) {
            case 1:
                pause();
                break;
            case 2:
                resumeAudio();
                break;
            case 3:
                restart();
                break;
            case 4:
                System.out.println("Enter time (" + 0 + ", " + clip.getMicrosecondLength() + ")");
                Scanner sc = new Scanner(System.in);
                long c1 = sc.nextLong();
                jump(c1);
                break;
            case 7:
                stop();
                System.exit(0);

        }

    }

    // Method to play the audio
    public void play() {
        // start the clip
        clip.start();

        status = "play";
    }

    // Method to pause the audio
    public void pause() {
        if (status.equals("paused")) {
            System.out.println("audio is already paused");
            return;
        }
        this.currentFrame = this.clip.getMicrosecondPosition();
        clip.stop();
        status = "paused";
    }

    // Method to resume the audio
    public void resumeAudio() throws UnsupportedAudioFileException, IOException, LineUnavailableException {
        if (status.equals("play")) {
            System.out.println("Audio is already " + "being played");
            return;
        }
        clip.close();
        resetAudioStream();
        clip.setMicrosecondPosition(currentFrame);
        this.play();
    }

    // Method to exit
    public void stop() throws UnsupportedAudioFileException, IOException, LineUnavailableException {
        currentFrame = 0L;
        clip.stop();
        clip.close();
    }

    // Method to jump over a specific part
    public void jump(long c) throws UnsupportedAudioFileException, IOException, LineUnavailableException {
        if (c > 0 && c < clip.getMicrosecondLength()) {
            clip.stop();
            clip.close();
            resetAudioStream();
            currentFrame = c;
            clip.setMicrosecondPosition(c);
            this.play();
        }
    }

    // Method to restart the audio
    public void restart() throws IOException, LineUnavailableException, UnsupportedAudioFileException {
        clip.stop();
        clip.close();
        resetAudioStream();
        currentFrame = 0L;
        clip.setMicrosecondPosition(0);
        this.play();
    }

    // Method to reset audio stream
    public void resetAudioStream() throws UnsupportedAudioFileException, IOException, LineUnavailableException {
        audioInputStream = AudioSystem.getAudioInputStream(new File(filePath).getAbsoluteFile());
        clip.open(audioInputStream);
        clip.loop(Clip.LOOP_CONTINUOUSLY);
    }


}

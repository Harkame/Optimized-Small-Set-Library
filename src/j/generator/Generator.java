package j.generator;

import java.io.FileWriter;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.VelocityEngine;

public class Generator {

    public static void createOneFile(int offset) {
        String innerSetClassName = "InnerSet_" + offset;
        ArrayList<Integer> elements = new ArrayList<>();
        for(int i = 1; i <= offset; i++) {
            elements.add(i);
        }

        try {
            VelocityEngine engine = new VelocityEngine();
            engine.init();

            Template template = engine.getTemplate("src/j/generator/InnserSetTemplate.vm");

            VelocityContext context = new VelocityContext();
            context.put("innerSetOffset", offset);
            context.put("nextInnerSet", offset + 1);
            context.put("previousInnerSet", offset - 1);
            context.put("innerSetClassName", innerSetClassName);
            context.put("elements", elements);

            FileWriter writer = new FileWriter("generated/" + innerSetClassName + ".java");

            template.merge(context, writer);

            writer.flush();
        } catch (Exception ex) {
            System.err.println(ex);
        }
    }

    public static void main(String[] args) {
        createOneFile(1);
    }

}

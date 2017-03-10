package cpp.generator;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.VelocityEngine;
import org.apache.velocity.runtime.RuntimeConstants;

import java.io.File;
import java.io.FileWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Generator {

    static int TO_GENERATE = 3;

    public static void createOneFile(int offset) {
        String innerSetClassName = "inner_set_" + offset;
        ArrayList<String> elements = new ArrayList<>();
        for(int i = 1; i <= offset; i++) {
            elements.add("element_" + i);
        }

        try {
            VelocityEngine engine = new VelocityEngine();
            String pathToTemplate = "src/cpp/generator/";
            String pathToGenerated = "src/cpp/implementation/test/";
            engine.setProperty(RuntimeConstants.RESOURCE_LOADER, "file");
            engine.setProperty(RuntimeConstants.FILE_RESOURCE_LOADER_PATH, pathToTemplate);
            engine.init();
            Template template = engine.getTemplate("InnerSetTemplate.vm");

            VelocityContext context = new VelocityContext();
            context.put("innerSetOffset", offset);
            context.put("nextInnerSet", "inner_set_" + (offset + 1));
            context.put("lastInnerSet", TO_GENERATE);
            context.put("previousInnerSet", "inner_set_" + (offset - 1));
            context.put("innerSetClassName", innerSetClassName);
            context.put("elements", elements);
            context.put("innerSetClassNameDefine", innerSetClassName.toUpperCase() + "_H");

            Path dir = Paths.get(pathToGenerated);
            Files.createDirectories(dir);
            FileWriter writer = new FileWriter(new File(pathToGenerated + innerSetClassName + ".cpp"), false);

            template.merge(context, writer);

            writer.flush();
        } catch (Exception ex) {
            System.err.println(ex);
        }
    }

    public static void main(String[] args) {
        for(int i = 1; i <= TO_GENERATE; i++)
        createOneFile(i);
    }

}

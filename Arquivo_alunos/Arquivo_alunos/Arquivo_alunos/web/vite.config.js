import {defineConfig} from "vite";
import {resolve} from "node:path";

export default defineConfig({
  build:{
    rollupOptions:{
      input:{
        principal:resolve(import.meta.dirname,"index.html"),
        modelo:resolve(import.meta.dirname,"modelo.html")
      }
    }
  }
});

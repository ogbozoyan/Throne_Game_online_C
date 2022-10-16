import dearpygui.dearpygui as dpg
import dearpygui.demo as demo
import gitinterface as gi

def start():
    dpg.create_context()

    with dpg.window(tag="Primary Window"):
        dpg.add_text("Hello, world")
        dpg.add_button(label="Save")
        dpg.add_input_text(label="string", default_value="Quick brown fox")
        dpg.add_slider_float(label="float", default_value=0.273, max_value=1)

    dpg.create_viewport(title='Custom Title', width=400, height=300)
    dpg.setup_dearpygui()
    dpg.show_viewport()
    dpg.set_primary_window("Primary Window", True)
    dpg.start_dearpygui()
    dpg.destroy_context()

